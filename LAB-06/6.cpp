#include <iostream>
using namespace std;

// Base class: Student
class Student {
protected:
    string name;
    int rollNo;
public:
    void setStudentDetails(string n, int r) {
        name = n;
        rollNo = r;
    }
    void displayStudentDetails() {
        cout << "Student Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
    }
};

// Derived class: Marks (inherits Student)
class Marks : public Student {
protected:
    int courseMarks[3];
public:
    void setMarks(int m1, int m2, int m3) {
        courseMarks[0] = m1;
        courseMarks[1] = m2;
        courseMarks[2] = m3;
    }
    void displayMarks() {
        cout << "Marks Obtained:" << endl;
        for (int i = 0; i < 3; i++) {
            cout << "Course " << (i + 1) << ": " << courseMarks[i] << endl;
        }
    }
};

// Derived class: Result (inherits Marks)
class Result : public Marks {
public:
    void displayResult() {
        int totalMarks = courseMarks[0] + courseMarks[1] + courseMarks[2];
        float averageMarks = totalMarks / 3.0;
        
        cout << "Total Marks: " << totalMarks << endl;
        cout << "Average Marks: " << averageMarks << endl;
    }
};

int main() {
    Result student1;
    
    student1.setStudentDetails("Sanjna", 101);
    student1.setMarks(85, 90, 95);
    
    cout << "--- Student Details ---" << endl;
    student1.displayStudentDetails();
    
    cout << "\n--- Marks Details ---" << endl;
    student1.displayMarks();
    
    cout << "\n--- Result ---" << endl;
    student1.displayResult();
    
    return 0;
}
