#include <iostream>
#include <string>
using namespace std;

class Car {
protected:
    string model;
    float price;

public:
    Car(string m) : model(m), price(0.0f) {}

    void setModel(string m) {
        model = m;
    }

    string getModel() const {
        return model;
    }

    float getPrice() const {
        return price;
    }

    virtual void setPrice(float p) = 0;

    virtual ~Car() {}
};

class Color : public Car {
private:
    string carColor;

public:
    Color(string m, string c) : Car(m), carColor(c) {}

    void setPrice(float p) override {
        price = p + 500;
    }

    string getColor() const {
        return carColor;
    }

    void display() {
        cout << "Color Car - Model: " << model
             << ", Color: " << carColor
             << ", Price: $" << price << endl;
    }
};

class Company : public Car {
private:
    string companyName;

public:
    Company(string m, string comp) : Car(m), companyName(comp) {}

    void setPrice(float p) override {
        if (companyName == "Toyota") price = p + 1000;
        else if (companyName == "BMW") price = p + 5000;
        else price = p + 300; 
    }

    string getCompany() const {
        return companyName;
    }

    void display() {
        cout << "Company Car - Model: " << model
             << ", Company: " << companyName
             << ", Price: $" << price << endl;
    }
};

int main() {
    Color colorCar("Civic", "Red");
    colorCar.setPrice(20000);
    colorCar.display();

    Company companyCar("X5", "BMW");
    companyCar.setPrice(30000);
    companyCar.display();

    return 0;
}
