#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string position;
    string color;
    double borderThickness;

public:
    Shape(string pos, string col, double border = 1.0)
        : position(pos), color(col), borderThickness(border) {}

    virtual void draw() {
        cout << "Drawing a generic shape at " << position << " with color " << color << endl;
    }

    virtual double calculateArea() {
        return 0.0;
    }

    virtual double calculatePerimeter() {
        return 0.0;
    }

    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;

public:
    Circle(string pos, string col, double r) : Shape(pos, col), radius(r) {}

    void draw() override {
        cout << "Drawing a Circle at " << position << " with radius " << radius << endl;
    }

    double calculateArea() override {
        return 3.14* radius * radius;
    }

    double calculatePerimeter() override {
        return 2 * 3.14 * radius;
    }
};

class Rectangle : public Shape {
    double width, height;

public:
    Rectangle(string pos, string col, double w, double h)
        : Shape(pos, col), width(w), height(h) {}

    void draw() override {
        cout << "Drawing a Rectangle at " << position << " with width " << width << " and height " << height << endl;
    }

    double calculateArea() override {
        return width * height;
    }

    double calculatePerimeter() override {
        return 2 * (width + height);
    }
};

int main() {
    Circle c("Center (5,5)", "Red", 3.0);
    Rectangle r("Top-Left (2,2)", "Blue", 4.0, 6.0);

    c.draw();
    cout << "Circle Area: " << c.calculateArea() << endl;
    cout << "Circle Perimeter: " << c.calculatePerimeter() << endl;

    cout << "---------------------" << endl;

    r.draw();
    cout << "Rectangle Area: " << r.calculateArea() << endl;
    cout << "Rectangle Perimeter: " << r.calculatePerimeter() << endl;

    return 0;
}
