#include <iostream>
using namespace std;

class Shape {
private:
    float area;

public:
    // Constructor to set area
    Shape(float a) : area(a) {}

    // Area function (returns the area of the shape)
    float Area() const {
        return area;
    }

    // Overload the + operator to add areas of two shapes
    float operator+(const Shape& other) const {
        return this->area + other.area;
    }
};

int main() {
    Shape shape1(20.5);  // Shape1 with area 20.5
    Shape shape2(30.3);  // Shape2 with area 30.3

    // Adding areas of shape1 and shape2 using overloaded + operator
    float totalArea = shape1 + shape2;

    cout << "Total Area (shape1 + shape2): " << totalArea << endl;

    return 0;
}
