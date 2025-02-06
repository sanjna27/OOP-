#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Subject {
    string name; 
};

struct Student {
    int id; 
    Subject subjects[3]; 
};

int main() {
    vector<Student> students;
    Student s1;
    s1.id = 1;
    s1.subjects[0] = {"Math"};
    s1.subjects[1] = {"Science"};
    s1.subjects[2] = {"History"};
    students.push_back(s1);

    Student s2;
    s2.id = 2;
    s2.subjects[0] = {"English"};
    s2.subjects[1] = {"Physics"};
    s2.subjects[2] = {"Chemistry"};
    students.push_back(s2);

    for (const auto& student : students) {
        cout << "Student ID: " << student.id << endl;
        cout << "Subjects: ";
        for (const auto& subject : student.subjects) {
            cout << subject.name << " ";
        }
        cout << endl << endl;
    }

    return 0;
}
