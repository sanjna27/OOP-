#include <iostream>
#include <vector>
#include <string>
using namespace std;

void* AddToArray(void* arr, int size, int valueToAdd) {
    int* intArray = static_cast<int*>(arr);

    for (int i = 0; i < size; i++) {
        intArray[i] += valueToAdd;
    }

    return static_cast<void*>(intArray);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: " << argv[0] << " <value_to_add> <element1> <element2> ... <elementN>" << endl;
        return 1;
    }

    int valueToAdd = stoi(argv[1]);

    int size = argc - 2;
    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        arr[i] = stoi(argv[2 + i]);
    }

    void* modifiedArray = AddToArray(static_cast<void*>(arr), size, valueToAdd);

    int* resultArray = static_cast<int*>(modifiedArray);

    cout << "Modified Array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << resultArray[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
