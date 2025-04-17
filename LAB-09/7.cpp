#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;

public:
    virtual void getData() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
    }

    virtual void displayData() {
        cout << "Name: " << name << ", ID: " << id << endl;
    }

    virtual void bonus() {
        cout << "Base person has no bonus logic.\n";
    }

    virtual ~Person() {}
};

class Admin : virtual public Person {
protected:
    float adminSalary;

public:
    void getData() override {
        Person::getData();
        cout << "Enter Admin Salary: ";
        cin >> adminSalary;
    }

    void displayData() override {
        Person::displayData();
        cout << "Admin Salary: $" << adminSalary << endl;
    }

    void bonus() override {
        cout << "Admin Bonus: $" << (adminSalary * 0.15) << endl;
    }
};

class Account : virtual public Person {
protected:
    float accountSalary;

public:
    void getData() override {
        Person::getData();
        cout << "Enter Account Salary: ";
        cin >> accountSalary;
    }

    void displayData() override {
        Person::displayData();
        cout << "Account Salary: $" << accountSalary << endl;
    }

    void bonus() override {
        cout << "Account Bonus: $" << (accountSalary * 0.10) << endl;
    }
};

class Master : public Admin, public Account {
private:
    float masterBonus;

public:
    void getData() override {
        Person::getData();
        cout << "Enter Admin Salary: ";
        cin >> adminSalary;
        cout << "Enter Account Salary: ";
        cin >> accountSalary;
        cout << "Enter Master Bonus: ";
        cin >> masterBonus;
    }

    void displayData() override {
        Person::displayData();
        cout << "Admin Salary: $" << adminSalary << endl;
        cout << "Account Salary: $" << accountSalary << endl;
        cout << "Master Bonus Add-on: $" << masterBonus << endl;
    }

    void bonus() override {
        float totalBonus = (adminSalary * 0.15) + (accountSalary * 0.10) + masterBonus;
        cout << "Total Master Bonus: $" << totalBonus << endl;
    }
};
int main() {
    Person* ptr;

    cout << "\n Admin Employee \n";
    Admin a;
    ptr = &a;
    ptr->getData();
    ptr->displayData();
    ptr->bonus();

    cout << "\nAccount Employee\n";
    Account acc;
    ptr = &acc;
    ptr->getData();
    ptr->displayData();
    ptr->bonus();

    cout << "\nMaster Employee\n";
    Master m;
    ptr = &m;
    ptr->getData();
    ptr->displayData();
    ptr->bonus();

    return 0;
}
