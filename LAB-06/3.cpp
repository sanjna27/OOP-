#include <iostream>
using namespace std;

class Employee {
protected:
    int id;
    string name;
public:
    Employee(int empId, string empName) : id(empId), name(empName) {}

    void displayInfo() {
        cout << "Employee ID: " << id << ", Name: " << name << endl;
    }
};

class IOrderTaker {
public:
    virtual void takeOrder(string order) = 0; // Pure virtual function
};
class IOrderPreparer {
public:
    virtual void prepareOrder(string order) = 0; // Pure virtual function
};
class IBiller {
public:
    virtual void generateBill(double amount) = 0; // Pure virtual function
};
class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int empId, string empName) : Employee(empId, empName) {}

    void takeOrder(string order) override {
        cout << name << " (Waiter) is taking order: " << order << endl;
    }
};
class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int empId, string empName) : Employee(empId, empName) {}

    void prepareOrder(string order) override {
        cout << name << " (Chef) is preparing order: " << order << endl;
    }
};
class Cashier : public Employee, public IBiller {
public:
    Cashier(int empId, string empName) : Employee(empId, empName) {}

    void generateBill(double amount) override {
        cout << name << " (Cashier) generated bill: $" << amount << endl;
    }
};
class Menu {
protected:
    string items[5]; 
    double prices[5];
    int itemCount; 
public:
    Menu() : itemCount(0) {} 

    void addItem(string item, double price) {
        if (itemCount < 5) { 
            items[itemCount] = item;
            prices[itemCount] = price;
            itemCount++;
        } else {
            cout << "Menu is full, cannot add more items." << endl;
        }
    }

    void displayMenu() {
        cout << "Menu:\n";
        for (int i = 0; i < itemCount; i++) {
            cout << items[i] << " - $" << prices[i] << endl;
        }
    }

    double getPrice(string item) {
        for (int i = 0; i < itemCount; i++) {
            if (items[i] == item)
                return prices[i];
        }
        return 0; 
    }
};
class FoodMenu : public Menu {
public:
    FoodMenu() {
        addItem("Burger", 5.0);
        addItem("Pizza", 8.0);
    }
};
class BeverageMenu : public Menu {
public:
    BeverageMenu() {
        addItem("Coke", 2.0);
        addItem("Coffee", 3.0);
    }

    double applyBeverageTax(double total) {
        return total * 1.1; 
    }
};

int main() {
    Waiter waiter1(101, "John");
    Chef chef1(102, "Ayeha");
    Cashier cashier1(103, "Sanjna");

    FoodMenu foodMenu;
    BeverageMenu beverageMenu;

    cout << "\n--- Food Menu ---\n";
    foodMenu.displayMenu();

    cout << "\n--- Beverage Menu ---\n";
    beverageMenu.displayMenu();

    waiter1.takeOrder("Pizza");

    chef1.prepareOrder("Pizza");

    double price = foodMenu.getPrice("Pizza");
    cashier1.generateBill(price);

    return 0;
}
