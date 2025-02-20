#include <iostream>
#include <vector>
#include <limits>  
using namespace std;

struct MenuItem {
    string name;
    string type;
    double price;
};

class CoffeeShop {
private:
    string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string shopName, vector<MenuItem> shopMenu)
        : name(shopName), menu(shopMenu) {}

    string addOrder(string itemName) {
        for (const auto& item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string item = orders.front();
            orders.erase(orders.begin());
            return "The " + item + " is ready";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0;
        for (const auto& order : orders) {
            for (const auto& item : menu) {
                if (order == item.name) {
                    total += item.price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "No items on the menu";

        double minPrice = numeric_limits<double>::max();
        string cheapestItem = "";

        for (const auto& item : menu) {
            if (item.price < minPrice) {
                minPrice = item.price;
                cheapestItem = item.name;
            }
        }
        return cheapestItem;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (const auto& item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> foods;
        for (const auto& item : menu) {
            if (item.type == "food") {
                foods.push_back(item.name);
            }
        }
        return foods;
    }
};

int main() {
    vector<MenuItem> shopMenu = {
        {"Espresso", "drink", 2.5},
        {"Latte", "drink", 3.0},
        {"Cappuccino", "drink", 3.5},
        {"Croissant", "food", 4.0},
        {"Bagel", "food", 3.0},
        {"Muffin", "food", 2.0}
    };

    CoffeeShop myShop("JavaBeans Café", shopMenu);

    cout << myShop.addOrder("Latte") << endl;
    cout << myShop.addOrder("Muffin") << endl;
    cout << myShop.addOrder("Green Tea") << endl;

    cout << myShop.fulfillOrder() << endl;
    cout << myShop.fulfillOrder() << endl;
    cout << myShop.fulfillOrder() << endl;

    vector<string> currentOrders = myShop.listOrders();
    cout << "Current Orders: ";
    if (currentOrders.empty()) {
        cout << "No orders\n";
    } else {
        for (const string& order : currentOrders) {
            cout << order << " ";
        }
        cout << endl;
    }

    cout << "Total Due: $" << myShop.dueAmount() << endl;
    cout << "Cheapest Item: " << myShop.cheapestItem() << endl;

    cout << "Drinks Menu: ";
    for (const string& drink : myShop.drinksOnly()) {
        cout << drink << " ";
    }
    cout << endl;

    cout << "Food Menu: ";
    for (const string& food : myShop.foodOnly()) {
        cout << food << " ";
    }
    cout << endl;

    return 0;
}
