#include <iostream>
using namespace std;

class Car {
public:
    mutable int engine_horsepower;
    mutable int seating_capacity;
    mutable int no_of_speakers;

    Car(int hp, int seats, int speakers)
        : engine_horsepower(hp), seating_capacity(seats), no_of_speakers(speakers) {}

    void display() const {
        cout << "Engine Horsepower: " << engine_horsepower << endl;
        cout << "Seating Capacity: " << seating_capacity << endl;
        cout << "Number of Speakers: " << no_of_speakers << endl;
    }

    void modifyAttributes(int hp, int seats, int speakers) const {
        engine_horsepower = hp;
        seating_capacity = seats;
        no_of_speakers = speakers;
    }
};

int main() {
    Car myCar(175, 5, 7);
    myCar.display();

    myCar.modifyAttributes(185, 7, 8);  // Modifying via const function
    cout << "\nAfter Modification:\n";
    myCar.display();

    return 0;
}
