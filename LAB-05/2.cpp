#include <iostream>
#include <vector>
using namespace std;

class Car {
public:
    string name;
    int id;
    Car(string n, int i) : name(n), id(i) {}
    void display() const {
        cout << "Car ID: " << id << ", Name: " << name << endl;
    }
};

class Garage {
private:
    vector<Car*> cars; // Aggregation
public:
    void parkCar(Car* car) {
        cars.push_back(car);
    }
    void listCars() const {
        for (const auto& car : cars) {
            car->display();
        }
    }
};

int main() {
    Car car1("Toyota", 1);
    Car car2("Honda", 2);
    
    Garage myGarage;
    myGarage.parkCar(&car1);
    myGarage.parkCar(&car2);
    
    myGarage.listCars();
    return 0;
}
