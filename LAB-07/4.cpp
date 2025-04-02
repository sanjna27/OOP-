#include <iostream>
using namespace std;

// Base class
class Person {
protected:
    string name, id, address, phoneNumber, email;
public:
    Person(string n, string i, string addr, string phone, string mail)
        : name(n), id(i), address(addr), phoneNumber(phone), email(mail) {}

    virtual void displayInfo() {
        cout << "Name: " << name << "\nID: " << id << "\nAddress: " << address
             << "\nPhone: " << phoneNumber << "\nEmail: " << email << endl;
    }

    void updateInfo(string newAddress, string newPhone, string newEmail) {
        address = newAddress;
        phoneNumber = newPhone;
        email = newEmail;
        cout << "Information updated successfully!\n";
    }
};

// Derived Student class
class Student : public Person {
private:
    string course1, course2;
    double GPA;
    int enrollmentYear;
public:
    Student(string n, string i, string addr, string phone, string mail, 
            string c1, string c2, double gpa, int year)
        : Person(n, i, addr, phone, mail), course1(c1), course2(c2), GPA(gpa), enrollmentYear(year) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "GPA: " << GPA << "\nEnrollment Year: " << enrollmentYear
             << "\nCourses: " << course1 << ", " << course2 << endl;
    }

    void updateInfo(double newGPA, string newCourse1, string newCourse2) {
        GPA = newGPA;
        course1 = newCourse1;
        course2 = newCourse2;
        cout << "Student info updated successfully!\n";
    }
};

// Derived Professor class
class Professor : public Person {
private:
    string department, course1, course2;
    double salary;
public:
    Professor(string n, string i, string addr, string phone, string mail, 
              string dept, string c1, string c2, double sal)
        : Person(n, i, addr, phone, mail), department(dept), course1(c1), course2(c2), salary(sal) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << "\nSalary: " << salary
             << "\nCourses Taught: " << course1 << ", " << course2 << endl;
    }

    void updateInfo(double newSalary, string newCourse1, string newCourse2) {
        salary = newSalary;
        course1 = newCourse1;
        course2 = newCourse2;
        cout << "Professor info updated successfully!\n";
    }
};

// Derived Staff class
class Staff : public Person {
private:
    string department, position;
    double salary;
public:
    Staff(string n, string i, string addr, string phone, string mail, 
          string dept, string pos, double sal)
        : Person(n, i, addr, phone, mail), department(dept), position(pos), salary(sal) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << "\nPosition: " << position
             << "\nSalary: " << salary << endl;
    }

    void updateInfo(string newPosition, double newSalary) {
        position = newPosition;
        salary = newSalary;
        cout << "Staff info updated successfully!\n";
    }
};

// Main function
int main() {
    Student s("Sanjna", "S123", "123 Street", "1234567890", "sanjna@example.com", 
              "CS", "Physics", 3.8, 2024);
    Professor p("Mr.Monis", "P456", "456 Avenue", "9876543210", "monis@example.com", 
                "Computer Science", "AI", "OOP", 70000);
    Staff st("Charlie", "ST789", "789 Road", "1112223333", "charlie@example.com", 
             "Admin", "Clerk", 40000);
    
    cout << "Before Update:\n";
    s.displayInfo();
    cout << "--------------------\n";
    
    // Updating student info
    s.updateInfo(4.0, "Data Structures", "Algorithms");
    cout << "\nAfter Update:\n";
    s.displayInfo();
    
    return 0;
}
