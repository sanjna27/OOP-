#include <iostream>
using namespace std;

class Employee {
private:
    string firstName;
    string lastName;
    double monthlySalary;

public:
    Employee(string fName, string lName, double salary) {
        firstName = fName;
        lastName = lName;
        if (salary > 0) {
            monthlySalary = salary;
        } else {
            monthlySalary = 0.0; 
        }
    }

    double getYearlySalary() {
        return monthlySalary * 12;
    }

    void giveRaise() {
        monthlySalary *= 1.1;
    }

    void display() {
        cout << "Employee: " << firstName << " " << lastName << endl;
        cout << "Yearly Salary: $" << getYearlySalary() << endl;
    }
};

int main() {
    Employee emp1("Sanjna", "Kataria", 30000);
    Employee emp2("Anshul", "Kataria", 40000);

    cout << "Before Raise:" << endl;
    emp1.display();
    emp2.display();

    emp1.giveRaise();
    emp2.giveRaise();

    cout << "\nAfter 10% Raise:" << endl;
    emp1.display();
    emp2.display();

    return 0;
}
