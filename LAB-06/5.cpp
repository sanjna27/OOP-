#include <iostream>
using namespace std;

class Vehicles {
protected:
    double price;
public:
    Vehicles(double p) : price(p) {}

    void displayPrice() {
        cout << "Price: $" << price << endl;
    }
};
class Car : public Vehicles {
protected:
    int seatingCapacity, numDoors;
    string fuelType;
public:
    Car(double p, int seat, int doors, string fuel) 
        : Vehicles(p), seatingCapacity(seat), numDoors(doors), fuelType(fuel) {}

    void displayCarDetails() {
        displayPrice();
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "Number of Doors: " << numDoors << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }
};
class Motorcycle : public Vehicles {
protected:
    int numCylinders, numGears, numWheels;
public:
    Motorcycle(double p, int cylinders, int gears, int wheels) 
        : Vehicles(p), numCylinders(cylinders), numGears(gears), numWheels(wheels) {}

    void displayMotorcycleDetails() {
        displayPrice();
        cout << "Number of Cylinders: " << numCylinders << endl;
        cout << "Number of Gears: " << numGears << endl;
        cout << "Number of Wheels: " << numWheels << endl;
    }
};
class Audi : public Car {
private:
    string modelType;
public:
    Audi(double p, int seat, int doors, string fuel, string model) 
        : Car(p, seat, doors, fuel), modelType(model) {}

    void displayAudiDetails() {
        displayCarDetails();
        cout << "Model Type: " << modelType << endl;
    }
};
class Yamaha : public Motorcycle {
private:
    string makeType;
public:
    Yamaha(double p, int cylinders, int gears, int wheels, string make) 
        : Motorcycle(p, cylinders, gears, wheels), makeType(make) {}

    void displayYamahaDetails() {
        displayMotorcycleDetails();
        cout << "Make Type: " << makeType << endl;
    }
};

int main() {
    Audi myAudi(50000, 5, 4, "Petrol", "A6");
    Yamaha myYamaha(15000, 2, 6, 2, "YZF-R1");

    cout << "Audi Car Details:\n";
    myAudi.displayAudiDetails();
    
    cout << "\nYamaha Motorcycle Details:\n";
    myYamaha.displayYamahaDetails();

    return 0;
}
