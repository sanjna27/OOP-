#include <iostream>
using namespace std;

int* ResizeArray(int* arr, int& size, int newSize) {
    int* newArr = new int[newSize];

    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    size = newSize;
    return newArr;
}

int main() {
    int initialSize = 5; 
    int* arr = new int[initialSize];
    int count = 0; 

    int input;
    cout << "Enter integers (enter -1 to stop):" << endl;
    while (true) {
        cin >> input;
        if (input == -1) {
            break; 
        }

        arr[count] = input;
        count++;

        if (count >= 2 * initialSize) {
            cout << "Resizing array from " << initialSize << " to " << 2 * initialSize << endl;
            arr = ResizeArray(arr, initialSize, 2 * initialSize);
        }
    }

    if (count < initialSize) {
        cout << "Resizing array from " << initialSize << " to " << count << endl;
        arr = ResizeArray(arr, initialSize, count);
    }

    cout << "Final array:" << endl;
    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;

    return 0;
}
