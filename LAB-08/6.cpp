#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int empID;  

public:
    void getData(int id) {
        empID = id;
    }
    void displayData() const {
        cout << "Employee ID: " << empID << endl;
    }
};

class Admin : public Person {
protected:
    string name;  
    float monthlyIncome;  

public:
    void getData(string empName, float income, int id) {
        name = empName;
        monthlyIncome = income;
        Person::getData(id);  
    }

    float bonus() const {
        return monthlyIncome * 0.05;  // 5% annual bonus
    }
    void displayData() const {
        Person::displayData();  // Calling base class function
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        cout << "Bonus: " << bonus() << endl;
    }
};

class Accounts : public Person {
protected:
    string name;  
    float monthlyIncome;  

public:
    void getData(string empName, float income, int id) {
        name = empName;
        monthlyIncome = income;
        Person::getData(id);  
    }

    float bonus() const {
        return monthlyIncome * 0.05;  // 5% annual bonus
    }

    void displayData() const {
        Person::displayData();  
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        cout << "Bonus: " << bonus() << endl;
    }
};

int main() {
    Admin admin1, admin2;
    Accounts acc1, acc2;

    admin1.getData("Sanjna", 3000, 101);
    admin2.getData("Smith", 3500, 102);

    acc1.getData("Michael ", 4000, 201);
    acc2.getData("Anshu", 4500, 202);

    // Display data for each employee
    cout << "\nAdmin Employee 1 Details:" << endl;
    admin1.displayData();
    cout << "\nAdmin Employee 2 Details:" << endl;
    admin2.displayData();
    cout << "\nAccounts Employee 1 Details:" << endl;
    acc1.displayData();
    cout << "\nAccounts Employee 2 Details:" << endl;
    acc2.displayData();

    return 0;
}
