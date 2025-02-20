#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* data;   
    int length;

public:
    DynamicArray() : data(nullptr), length(0) {}

    DynamicArray(int size) : length(size) {
        data = new int[length]();  
    }

    DynamicArray(const DynamicArray& other) {
        length = other.length;
        data = new int[length];  
        for (int i = 0; i < length; i++) {
            data[i] = other.data[i];  
        }
    }

    DynamicArray(DynamicArray&& other) noexcept 
        : data(other.data), length(other.length) {
        other.data = nullptr;  
        other.length = 0;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) return *this;  

        delete[] data;  

        length = other.length;
        data = new int[length];  
        for (int i = 0; i < length; i++) {
            data[i] = other.data[i];  
        }

        return *this;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this == &other) return *this;  

        delete[] data;  

        data = other.data;  
        length = other.length;

        other.data = nullptr;  
        other.length = 0;

        return *this;
    }

    ~DynamicArray() {
        delete[] data;
    }

    int size() const {
        return length;
    }

    int& at(int index) {
        if (index < 0 || index >= length) {
            throw out_of_range("Index out of bounds");
        }
        return data[index];
    }

    void resize(int newSize) {
        if (newSize == length) return; 

        int* newData = new int[newSize]();  

        for (int i = 0; i < min(length, newSize); i++) {
            newData[i] = data[i];
        }

        delete[] data;  
        data = newData;
        length = newSize;
    }

    void display() const {
        for (int i = 0; i < length; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray arr1;
    cout << "Array 1 (default constructor, empty): ";
    arr1.display();

    DynamicArray arr2(5);
    cout << "Array 2 (size 5, initialized to 0): ";
    arr2.display();

    for (int i = 0; i < arr2.size(); i++) {
        arr2.at(i) = i * 10;
    }
    cout << "Array 2 after setting values: ";
    arr2.display();

    DynamicArray arr3 = arr2;
    cout << "Array 3 (copy of Array 2): ";
    arr3.display();

    DynamicArray arr4 = move(arr2);
    cout << "Array 4 (moved from Array 2): ";
    arr4.display();

    arr1 = arr3;
    cout << "Array 1 (after copying from Array 3): ";
    arr1.display();

    arr1 = move(arr3);
    cout << "Array 1 (after moving from Array 3): ";
    arr1.display();

    arr1.resize(8);
    cout << "Array 1 after resizing to 8: ";
    arr1.display();

    return 0;
}
