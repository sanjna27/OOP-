#include <iostream>
using namespace std;

class Glass {
public:
    int LiquidLevel;

    Glass() {
        LiquidLevel = 200; 
    }

    void Drink(int milliliters) {
        LiquidLevel -= milliliters;  
        if (LiquidLevel < 100) {
            Refill();  
        }
    }

    void Refill() {
        LiquidLevel = 200;  
        cout << "Glass refilled to 200 ml!" << endl;
    }
};

int main() {
    Glass glass;
    string command;
    int amount;

    while (true) {
        cout << "Enter 'drink' to drink from the glass, 'exit' to quit: ";
        cin >> command;

        if (command == "drink") {
            cout << "Enter the amount of liquid to drink (ml): ";
            cin >> amount;
            glass.Drink(amount);
            cout << "Current Liquid Level: " << glass.LiquidLevel << " ml" << endl;
        }
        else if (command == "exit") {
            break;  
        }
        else {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}

