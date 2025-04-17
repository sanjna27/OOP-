#include <iostream>
#include <string>
using namespace std;

class Wallet {
private:
    double balance;  
    double dailyLimit;  
    double dailyTransactionTotal;  

public:
    Wallet(double b = 0.0, double limit = 500.0)
        : balance(b), dailyLimit(limit), dailyTransactionTotal(0.0) {}

    bool deposit(double amount) {
        if (amount <= 0) {
            cout << "Error: Deposit amount must be positive." << endl;
            return false;
        }
        if (dailyTransactionTotal + amount > dailyLimit) {
            cout << "Error: Exceeding daily deposit limit!" << endl;
            return false;
        }

        balance += amount;
        dailyTransactionTotal += amount;
        cout << "Deposited: $" << amount << " | New Balance: $" << balance << endl;
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error: Withdrawal amount must be positive." << endl;
            return false;
        }
        if (amount > balance) {
            cout << "Error: Insufficient funds!" << endl;
            return false;
        }
        if (dailyTransactionTotal + amount > dailyLimit) {
            cout << "Error: Exceeding daily withdrawal limit!" << endl;
            return false;
        }

        balance -= amount;
        dailyTransactionTotal += amount;
        cout << "Withdrawn: $" << amount << " | New Balance: $" << balance << endl;
        return true;
    }

    double getBalance() const {
        return balance;
    }

    void resetDailyLimit() {
        dailyTransactionTotal = 0;
    }
};

class User {
private:
    string userID;
    string name;
    Wallet wallet;

public:
    User(string id, string n, double b = 0.0)
        : userID(id), name(n), wallet(b) {}

    bool depositToWallet(double amount) {
        return wallet.deposit(amount);
    }

    bool withdrawFromWallet(double amount) {
        return wallet.withdraw(amount);
    }
    double getBalance() const {
        return wallet.getBalance();
    }
};

int main() {
    User user1("U1001", "Sanjna", 200.0);
    User user2("U1002", "Kataria", 100.0);

    user1.depositToWallet(150.0); 
    user1.withdrawFromWallet(50.0); 
    user2.depositToWallet(1000.0); 
    user2.withdrawFromWallet(200.0); 

    cout << "User1 Balance: $" << user1.getBalance() << endl;
    cout << "User2 Balance: $" << user2.getBalance() << endl;

    return 0;
}
