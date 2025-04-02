#include <iostream>
using namespace std;
class Account {
protected:
    int accountNumber;
    double balance;
    string accountHolderName;

public:
    Account(int accNo, double bal, string name) 
        : accountNumber(accNo), balance(bal), accountHolderName(name) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ", Remaining Balance: " << balance << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    virtual void calculateInterest() {
        cout << "Interest calculation varies for each account type." << endl;
    }

    virtual void printStatement() {
        cout << "[General Transactions] Account transactions recorded." << endl;
    }

    void getAccountInfo() {
        cout << "Account Holder: " << accountHolderName 
             << ", Account Number: " << accountNumber
             << ", Balance: " << balance << endl;
    }

    virtual ~Account() {}
};

class SavingsAccount : public Account {
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int accNo, double bal, string name, double rate, double minBal)
        : Account(accNo, bal, name), interestRate(rate), minimumBalance(minBal) {}

    void calculateInterest() override {
        double interest = balance * (interestRate / 100);
        cout << "Savings Account Interest: " << interest << endl;
    }

    void printStatement() override {
        cout << "[Savings Account Transactions] Interest earned, withdrawals, and deposits logged." << endl;
    }
};

class FixedDepositAccount : public Account {
    double fixedInterestRate;
    int maturityDate;

public:
    FixedDepositAccount(int accNo, double bal, string name, double rate, int matDate)
        : Account(accNo, bal, name), fixedInterestRate(rate), maturityDate(matDate) {}

    void calculateInterest() override {
        double interest = balance * (fixedInterestRate / 100);
        cout << "Fixed Deposit Interest: " << interest 
             << " (Maturity Date: " << maturityDate << ")" << endl;
    }

    void printStatement() override {
        cout << "[Fixed Deposit Transactions] Fixed interest applied, no withdrawals before maturity." << endl;
    }
};

int main() {
    SavingsAccount savings(1001, 5000, "Sanjna", 2.5, 1000);
    FixedDepositAccount fixedDep(1002, 10000, "Kataria", 5.0, 2028);

    cout << "Account Info:" << endl;
    savings.getAccountInfo();
    cout << endl;

    savings.deposit(1000);
    savings.withdraw(2000);
    savings.calculateInterest();
    
    cout << "Transaction Statement:" << endl;
    savings.printStatement();

    cout << "----------------------" << endl;

    cout << "Account Info:" << endl;
    fixedDep.getAccountInfo();
    cout << endl;

    fixedDep.deposit(2000);
    fixedDep.calculateInterest();
    
    cout << "Transaction Statement:" << endl;
    fixedDep.printStatement();

    return 0;
}
