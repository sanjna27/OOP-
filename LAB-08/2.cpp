#include <iostream>
#include <cmath>
using namespace std;

class Polynomial;  // Forward declaration for the friend class

// Friend class to access the internals of Polynomial
class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p, int x);
    static Polynomial derivative(const Polynomial& p);
};

class Polynomial {
private:
    int* coeffs;  // Array of coefficients
    int degree;   // Degree of the polynomial

public:
    // Default constructor (empty polynomial)
    Polynomial(int deg = 0) : degree(deg) {
        coeffs = new int[degree + 1]();  // Initialize with zeros
    }

    // Constructor from an array of coefficients
    Polynomial(int* c, int deg) : degree(deg) {
        coeffs = new int[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coeffs[i] = c[i];
        }
    }

    // Copy constructor
    Polynomial(const Polynomial& other) : degree(other.degree) {
        coeffs = new int[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coeffs[i] = other.coeffs[i];
        }
    }

    // Assignment operator
    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            delete[] coeffs;  // Deallocate current memory
            degree = other.degree;
            coeffs = new int[degree + 1];
            for (int i = 0; i <= degree; ++i) {
                coeffs[i] = other.coeffs[i];
            }
        }
        return *this;
    }

    // Destructor
    ~Polynomial() {
        delete[] coeffs;
    }

    // Addition of two polynomials
    Polynomial operator+(const Polynomial& other) const {
        int maxDegree = std::max(degree, other.degree);
        int* result = new int[maxDegree + 1]();

        for (int i = 0; i <= degree; ++i) {
            result[i] += coeffs[i];
        }
        for (int i = 0; i <= other.degree; ++i) {
            result[i] += other.coeffs[i];
        }

        Polynomial sum(result, maxDegree);
        delete[] result;  // Clean up temporary array
        return sum;
    }

    // Subtraction of two polynomials
    Polynomial operator-(const Polynomial& other) const {
        int maxDegree = std::max(degree, other.degree);
        int* result = new int[maxDegree + 1]();

        for (int i = 0; i <= degree; ++i) {
            result[i] += coeffs[i];
        }
        for (int i = 0; i <= other.degree; ++i) {
            result[i] -= other.coeffs[i];
        }

        Polynomial difference(result, maxDegree);
        delete[] result;  // Clean up temporary array
        return difference;
    }

    // Multiplication of two polynomials
    Polynomial operator*(const Polynomial& other) const {
        int newDegree = degree + other.degree;
        int* result = new int[newDegree + 1]();

        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                result[i + j] += coeffs[i] * other.coeffs[j];
            }
        }

        Polynomial product(result, newDegree);
        delete[] result;  // Clean up temporary array
        return product;
    }

    // Output polynomial in the form of ax^n + bx^(n-1) + ... + c
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
        if (p.degree < 0) {
            os << "0";
            return os;
        }

        bool first = true;
        for (int i = p.degree; i >= 0; --i) {
            int c = p.coeffs[i];
            if (c == 0) continue;

            if (!first) os << (c > 0 ? " + " : " - ");
            else if (c < 0) os << "-";

            int abs_c = std::abs(c);
            if (abs_c != 1 || i == 0) os << abs_c;
            if (i >= 1) os << "x";
            if (i >= 2) os << "^" << i;

            first = false;
        }
        return os;
    }

    // Make PolynomialUtils a friend class to access the internals
    friend class PolynomialUtils;
};

// Function to evaluate the polynomial at a given point x
int PolynomialUtils::evaluate(const Polynomial& p, int x) {
    int result = 0;
    int power = 1;
    for (int i = 0; i <= p.degree; ++i) {
        result += p.coeffs[i] * power;
        power *= x;
    }
    return result;
}

// Function to calculate the derivative of the polynomial
Polynomial PolynomialUtils::derivative(const Polynomial& p) {
    if (p.degree == 0) return Polynomial(0); // No derivative for a constant

    int* deriv = new int[p.degree];  // Derivative degree is one less than original
    for (int i = 1; i <= p.degree; ++i) {
        deriv[i - 1] = p.coeffs[i] * i;
    }

    Polynomial derivative(deriv, p.degree - 1);
    delete[] deriv;  // Clean up temporary array
    return derivative;
}

// Main function demonstrating the usage
int main() {
    // Polynomial: 2x^3 + 5x^2 - 1
    int p1_coeffs[] = {-1, 0, 5, 2};
    Polynomial p1(p1_coeffs, 3);

    // Polynomial: 4x + 3
    int p2_coeffs[] = {3, 4};
    Polynomial p2(p2_coeffs, 1);

    // Perform polynomial addition
    Polynomial sum = p1 + p2;

    // Perform polynomial subtraction
    Polynomial diff = p1 - p2;

    // Perform polynomial multiplication
    Polynomial prod = p1 * p2;

    // Print polynomials and results
    cout << "P1: " << p1 << endl;
    cout << "P2: " << p2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Product: " << prod << endl;

    // Evaluate p1 at x=2
    cout << "P1 evaluated at x=2: " << PolynomialUtils::evaluate(p1, 2) << endl;

    cout << "Derivative of P1: " << PolynomialUtils::derivative(p1) << endl;

    return 0;
}
