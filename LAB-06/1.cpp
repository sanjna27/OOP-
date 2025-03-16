#include<iostream>
#include<string>
using namespace std;

class BankAccount {
protected:
    int accountnumber;
    double balance;

public:
    BankAccount() { 
        accountnumber = 0;
        balance = 0;
    }
    
    BankAccount(int a, double b = 0) {
        accountnumber = a;
        balance = b;
    }

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << ", New Balance: " << balance << endl;
    }
    
    virtual bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << ", Remaining Balance: " << balance << endl;
            return true;
        } else {
            cout << "Insufficient funds!" << endl;
            return false;
        }
    }

    void display() const {
        cout << "Account Number: " << accountnumber << " | Balance: " << balance << endl;
    }
    
    int getAccountNumber() const { return accountnumber; }
    double getBalance() const { return balance; }
};

class SavingAccount : public BankAccount {
public:
    SavingAccount(int a, double b = 0) : BankAccount(a, b) {}
    void monthlyInterest() {
        balance += balance * 0.1;
        cout << "You have earned interest. New balance: " << balance << endl;
    }
};

class CheckingAccount : public BankAccount {
public:
    CheckingAccount(int a, double b = 0) : BankAccount(a, b) {}
    
    void overdraft(double withdraw) {
        if (withdraw > balance) {
            cout << "Alert! Overdraft limit exceeded." << endl;
            double loan = withdraw - balance;
            double tax = loan * 0.1;
            balance -= (loan + tax);  // Corrected logic to reflect new balance after overdraft
            cout << "Overdraft of " << loan << " granted. Tax applied: " << tax 
                 << ". New balance: " << balance << endl;
        }  
    }
};

class User {
protected:
    string name;
public:
    User(string n) : name(n) {}
    virtual void accessAccount(BankAccount &acc) = 0;
};

class Customer : public User {
private:
    BankAccount* account;
public:
    Customer(string n, BankAccount* acc) : User(n), account(acc) {}
    
    void deposit(double amount) {
        account->deposit(amount);
    }
    
    void withdraw(double amount) {
        if (!account->withdraw(amount)) {
            CheckingAccount* cAcc = dynamic_cast<CheckingAccount*>(account);
            if (cAcc) {
                cAcc->overdraft(amount);
            } else {
                cout << "Overdraft not available on this account." << endl;
            }
        }
    }
    
    void accessAccount(BankAccount &acc) override {
        cout << name << " is accessing account." << endl;
        acc.display();
    }
};

class Employee : public User {
public:
    Employee(string n) : User(n) {}
};

class Teller : public Employee {
public:
    Teller(string n) : Employee(n) {}
    void freezeAccount(BankAccount &acc) {
        cout << "The account: " << acc.getAccountNumber() << " has been frozen." << endl;
    }
    void accessAccount(BankAccount &acc) override {
        cout << name << " (Teller) is managing account." << endl;
        acc.display();
    }
};

class Manager : public Employee {
public:
    Manager(string n) : Employee(n) {}
    void overrideLimit() {
        cout << "Manager has overridden an account limit." << endl;
    }
    void accessAccount(BankAccount &acc) override {
        cout << name << " (Manager) is overseeing account." << endl;
        acc.display();
    }
};

int main() {
    SavingAccount acc(1001, 4000);
    acc.monthlyInterest();
    
    CheckingAccount cacc(1002, 4000);
    cacc.overdraft(5000);
    
    Customer c1("Sanjna", &acc);
    c1.deposit(200);
    c1.withdraw(5000);
    
    Teller t1("Kataria");
    t1.freezeAccount(acc);
    
    Manager m1("Rahul");
    m1.overrideLimit();
    
    return 0;
}
