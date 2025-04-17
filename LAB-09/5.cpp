#include <iostream>
using namespace std;

class Shape {
public:
    virtual double getArea() const = 0;
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double getArea() const override {
        return length * width;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;

public:
    Triangle(double b, double h) : base(b), height(h) {}

    double getArea() const override {
        return 0.5 * base * height;
    }
};

int main() {
    Rectangle rect(10.0, 5.0);  
    Triangle tri(6.0, 4.0);     

    cout << "Area of Rectangle: " << rect.getArea() << endl;
    cout << "Area of Triangle: " << tri.getArea() << endl;

    return 0;
}
