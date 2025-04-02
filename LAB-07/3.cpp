#include <iostream>
using namespace std;

// Base class
class Currency {
protected:
    double amount;
    string currencyCode, currencySymbol;
    double exchangeRate; // Rate relative to PKR (Base currency)

public:
    Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual void convertToBase() {
        cout << "Amount in PKR: " << amount * exchangeRate << " PKR" << endl;
    }

    virtual void displayCurrency() {
        cout << "Currency: " << currencyCode << " (" << currencySymbol << "), Amount: " << amount << endl;
    }
};

// Derived class for PKR (Base Currency)
class PKR : public Currency {
public:
    PKR(double amt) : Currency(amt, "PKR", "Rs", 1.0) {}

    void displayCurrency() override {
        cout << "Amount in PKR: Rs " << amount << endl;
    }
};

// Derived class for USD
class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 280.0) {} // 1 USD = 280 PKR (example rate)

    void convertToBase() override {
        cout << "Amount in PKR: " << amount * exchangeRate << " PKR" << endl;
    }
};

// Derived class for Euro
class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 300.0) {} // 1 EUR = 300 PKR (example rate)

    void convertToBase() override {
        cout << "Amount in PKR: " << amount * exchangeRate << " PKR" << endl;
    }
};

// Derived class for INR
class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", "₹", 3.4) {} // 1 INR = 3.4 PKR (example rate)

    void convertToBase() override {
        cout << "Amount in PKR: " << amount * exchangeRate << " PKR" << endl;
    }
};

int main() {
    PKR p(5000); // 5000 PKR
    Dollar d(10); // 10 USD
    Euro e(5); // 5 EUR
    Rupee r(100); // 100 INR

    p.displayCurrency();
    d.convertToBase();
    e.convertToBase();
    r.convertToBase();

    return 0;
}
