#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return (a < 0) ? -a : a; // Ensure GCD is always positive
    }

    void reduce() {
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;

        // Make denominator positive
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num = 0, int denom = 1) {
        if (denom == 0) {
            cout << "Denominator cannot be zero. Setting to 1.\n";
            denom = 1;
        }
        numerator = num;
        denominator = denom;
        reduce();
    }

    // Arithmetic Operators
    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
                        denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
                        denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator,
                        denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        return Fraction(numerator * other.denominator,
                        denominator * other.numerator);
    }

    // Relational Operators
    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const {
        return other < *this;
    }

    bool operator<=(const Fraction& other) const {
        return !(*this > other);
    }

    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    // Friend I/O operators
    friend ostream& operator<<(ostream& os, const Fraction& f) {
        if (f.denominator == 1)
            os << f.numerator;
        else
            os << f.numerator << "/" << f.denominator;
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& f) {
        char slash;
        is >> f.numerator >> slash >> f.denominator;
        f.reduce();
        return is;
    }
};

int main() {
    Fraction f1(2, 4), f2(3, 6);
    cout << (f1 + f2) << endl; // Output: 1
    return 0;
}
