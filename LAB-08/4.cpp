#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    // Constructor
    Number(int val) : value(val) {}

    // Prefix decrement operator (multiplies by 4)
    Number& operator--() {
        value *= 4;
        return *this;
    }

    // Postfix decrement operator (divides by 4)
    Number operator--(int) {
        Number temp = *this;
        value /= 4;
        return temp;
    }

    // Output the value
    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number num(8);

    cout << "Original number: ";
    num.display();

    // Using prefix decrement (multiplies by 4)
    --num;
    cout << "After prefix decrement (--num): ";
    num.display();

    // Using postfix decrement (divides by 4)
    num--;
    cout << "After postfix decrement (num--): ";
    num.display();

    return 0;
}
