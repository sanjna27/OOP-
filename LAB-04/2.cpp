#include <iostream>
using namespace std;

class Polynomial {
private:
    double* coefficients;  
    int degree; 

public:
    Polynomial() {
        degree = 0;
        coefficients = new double[1];  
        coefficients[0] = 0;  
    }

    Polynomial(int deg, const double coeffs[]) {
        degree = deg;
        coefficients = new double[degree + 1];  
        for (int i = 0; i <= degree; i++) {
            coefficients[i] = coeffs[i]; 
        }
    }

    Polynomial(const Polynomial& other) {
        degree = other.degree;
        coefficients = new double[degree + 1];  
        for (int i = 0; i <= degree; i++) {
            coefficients[i] = other.coefficients[i];  
        }
    }

    Polynomial(Polynomial&& other) noexcept {
        degree = other.degree;
        coefficients = other.coefficients;  
        other.coefficients = nullptr;  
        other.degree = 0;
    }

    ~Polynomial() {
        delete[] coefficients;  
    }

    int getDegree() const {
        return degree;
    }

    double evaluate(double x) const {
        double result = 0;
        double power = 1;  
        for (int i = 0; i <= degree; i++) {
            result += coefficients[i] * power;  
            power *= x;  
        }
        return result;
    }

   
    Polynomial add(const Polynomial& other) const {
        int maxDegree = max(degree, other.degree);
        double* newCoeffs = new double[maxDegree + 1]();

        for (int i = 0; i <= degree; i++) {
            newCoeffs[i] += coefficients[i];
        }
        for (int i = 0; i <= other.degree; i++) {
            newCoeffs[i] += other.coefficients[i];
        }

        return Polynomial(maxDegree, newCoeffs);
    }

    Polynomial multiply(const Polynomial& other) const {
        int newDegree = degree + other.degree;
        double* newCoeffs = new double[newDegree + 1]();

        for (int i = 0; i <= degree; i++) {
            for (int j = 0; j <= other.degree; j++) {
                newCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(newDegree, newCoeffs);
    }

    // Display polynomial
    void display() const {
        for (int i = degree; i >= 0; i--) {
            cout << coefficients[i] << "x^" << i;
            if (i > 0) cout << " + ";
        }
        cout << endl;
    }
};

int main() {
    double coeffs1[] = {3, 2, 1};  
    Polynomial poly1(2, coeffs1);

    double coeffs2[] = {1, 4};  
    Polynomial poly2(1, coeffs2);

    cout << "Polynomial 1: ";
    poly1.display();
    cout << "Polynomial 2: ";
    poly2.display();

    cout << "Polynomial 1 at x=2: " << poly1.evaluate(2) << endl;
    cout << "Polynomial 2 at x=2: " << poly2.evaluate(2) << endl;

    Polynomial sum = poly1.add(poly2);
    cout << "Sum: ";
    sum.display();

    Polynomial product = poly1.multiply(poly2);
    cout << "Product: ";
    product.display();

    return 0;
}
