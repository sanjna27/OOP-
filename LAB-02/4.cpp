#include <iostream>
#include <string>
using namespace std;

struct Organisation {
    string organisation_name;
    string organisation_number;

struct Employee {
        int employee_id;
        string name;
        double salary;
    } emp; 
};

int main() {
    Organisation org;
    
    cout << "Enter Organisation Name: ";
    cin >> org.organisation_name;
    
    cout << "Enter Organisation Number: ";
    cin >> org.organisation_number;
    
    cout << "Enter Employee ID: ";
    cin >> org.emp.employee_id;
    
    cout << "Enter Employee Name: ";
    cin >> org.emp.name;
    
    cout << "Enter Employee Salary: ";
    cin >> org.emp.salary;

    cout << "The size of structure organisation : " << sizeof(org) << endl;
    cout << "Organisation Name : " << org.organisation_name << endl ;
    cout << "Organisation Number : " << org.organisation_number << endl;
    cout << "Employee id : " << org.emp.employee_id << endl;
    cout << "Employee name : " << org.emp.name << endl;
    cout << "Employee Salary : " << org.emp.salary << endl;
    
    return 0;
}
