#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class BigInteger {
private:
    std::vector<int> digits;  // Digits of the number (least significant first)
    bool isNegative;  // Flag for negative numbers

    // Helper function to remove leading zeros
    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            isNegative = false;
        }
    }

public:
    // Default constructor (zero)
    BigInteger() : isNegative(false) {
        digits.push_back(0);  // Represent zero
    }

    // Constructor from string (e.g., "12345", "-12345")
    BigInteger(const std::string& str) {
        isNegative = str[0] == '-';
        int startIndex = isNegative ? 1 : 0;
        for (int i = str.size() - 1; i >= startIndex; --i) {
            digits.push_back(str[i] - '0');
        }
        removeLeadingZeros();
    }

    // Output BigInteger
    friend std::ostream& operator<<(std::ostream& os, const BigInteger& num) {
        if (num.isNegative) {
            os << "-";
        }
        for (int i = num.digits.size() - 1; i >= 0; --i) {
            os << num.digits[i];
        }
        return os;
    }

    // Input BigInteger
    friend std::istream& operator>>(std::istream& is, BigInteger& num) {
        std::string str;
        is >> str;
        num = BigInteger(str);  // Convert string to BigInteger
        return is;
    }

    // Addition of two BigIntegers
    BigInteger operator+(const BigInteger& other) const {
        if (this->isNegative == other.isNegative) {
            BigInteger result;
            result.isNegative = this->isNegative;
            int carry = 0;
            int maxSize = std::max(this->digits.size(), other.digits.size());

            for (int i = 0; i < maxSize || carry; ++i) {
                int sum = carry;
                if (i < this->digits.size()) sum += this->digits[i];
                if (i < other.digits.size()) sum += other.digits[i];
                carry = sum / 10;
                result.digits.push_back(sum % 10);
            }
            result.removeLeadingZeros();
            return result;
        }

        return *this - (-other);  // If different signs, use subtraction
    }

    // Subtraction of two BigIntegers
    BigInteger operator-(const BigInteger& other) const {
        if (this->isNegative != other.isNegative) {
            return *this + (-other);  // If signs differ, change subtraction to addition
        }

        // Ensure this is the larger number (in absolute value)
        bool resultNegative = false;
        const BigInteger* larger = this;
        const BigInteger* smaller = &other;

        if (this->isNegative) {
            if (*this < other) {
                larger = &other;
                smaller = this;
                resultNegative = true;
            }
        } else {
            if (*this < other) {
                larger = &other;
                smaller = this;
                resultNegative = true;
            }
        }

        BigInteger result;
        result.isNegative = resultNegative;
        int borrow = 0;
        int sizeDiff = larger->digits.size() - smaller->digits.size();

        for (int i = 0; i < larger->digits.size(); ++i) {
            int diff = larger->digits[i] - borrow;
            if (i - sizeDiff >= 0) {
                diff -= smaller->digits[i - sizeDiff];
            }
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits.push_back(diff);
        }
        result.removeLeadingZeros();
        return result;
    }

    // Negate the BigInteger (used in subtraction logic)
    BigInteger operator-() const {
        BigInteger result = *this;
        if (result.digits.size() > 1 || result.digits[0] != 0) {
            result.isNegative = !result.isNegative;
        }
        return result;
    }

    // Comparison operators
    bool operator==(const BigInteger& other) const {
        return this->isNegative == other.isNegative && this->digits == other.digits;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (this->isNegative != other.isNegative) {
            return this->isNegative;
        }

        if (this->digits.size() != other.digits.size()) {
            return this->digits.size() < other.digits.size();
        }

        for (int i = this->digits.size() - 1; i >= 0; --i) {
            if (this->digits[i] != other.digits[i]) {
                return this->digits[i] < other.digits[i];
            }
        }

        return false;
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger& other) const {
        return !(*this > other);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }
};

int main() {
    BigInteger num1, num2;
    std::cout << "Enter first BigInteger: ";
    std::cin >> num1;
    std::cout << "Enter second BigInteger: ";
    std::cin >> num2;

    std::cout << "Sum: " << num1 + num2 << std::endl;
    std::cout << "Difference: " << num1 - num2 << std::endl;
    std::cout << "Comparison (num1 == num2): " << (num1 == num2) << std::endl;
    std::cout << "Comparison (num1 < num2): " << (num1 < num2) << std::endl;
    std::cout << "Comparison (num1 > num2): " << (num1 > num2) << std::endl;

    return 0;
}
