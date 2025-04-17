#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string name;

public:
    Student(string n) : name(n) {}

    void setName(string n) {
        name = n;
    }

    string getName() const {
        return name;
    }

    virtual float getTuition(const string& status, int creditHours) = 0;

    virtual ~Student() {}
};

class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    GraduateStudent(string n, string topic = "")
        : Student(n), researchTopic(topic) {}

    void setResearchTopic(string topic) {
        researchTopic = topic;
    }

    string getResearchTopic() const {
        return researchTopic;
    }

    float getTuition(const string& status, int creditHours) override {
        if (status == "undergraduate")
            return creditHours * 200;
        else if (status == "graduate")
            return creditHours * 300;
        else if (status == "doctoral")
            return creditHours * 400;
        else {
            cout << "Invalid student status!\n";
            return 0;
        }
    }

    void displayInfo(const string& status, int creditHours) {
        cout << "Student Name: " << name << endl;
        cout << "Research Topic: " << researchTopic << endl;
        cout << "Status: " << status << ", Credit Hours: " << creditHours << endl;
        cout << "Calculated Tuition: $" << getTuition(status, creditHours) << endl;
    }
};

int main() {
    GraduateStudent gs("Sanjna", "Machine Learning");
    
    gs.displayInfo("graduate", 9); 

    cout << "\nTrying Doctoral status:\n";
    gs.displayInfo("doctoral", 6);

    return 0;
}
