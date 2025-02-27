#include <iostream>
#include <vector>
using namespace std;

struct MenuItem {
    string name;
    double price;
    string type; // "drink" or "food"
};

class CoffeeShop {
private:
    const string name;
    vector<MenuItem> menu;
    vector<string> orders;

public:
    CoffeeShop(string shopName, vector<MenuItem> menuItems) : name(shopName), menu(menuItems) {}

    string addOrder(string itemName) {
        for (const auto& item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added: " + itemName;
            }
        }
        return "This item is currently unavailable!";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string order = orders.front();
            orders.erase(orders.begin());
            return "The " + order + " is ready!";
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
                if (item.name == order) {
                    total += item.price;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "No items on the menu!";
        MenuItem cheapest = menu[0];
        for (const auto& item : menu) {
            if (item.price < cheapest.price) {
                cheapest = item;
            }
        }
        return cheapest.name;
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
        vector<string> food;
        for (const auto& item : menu) {
            if (item.type == "food") {
                food.push_back(item.name);
            }
        }
        return food;
    }
};

int main() {
    vector<MenuItem> menu = {
        {"Coffee", 2.5, "drink"},
        {"Tea", 1.5, "drink"},
        {"Sandwich", 5.0, "food"},
        {"Cake", 4.0, "food"}
    };

    CoffeeShop myShop("Sanjna Cafe", menu);

    cout << myShop.addOrder("Coffee") << endl;
    cout << myShop.addOrder("Burger") << endl;
    cout << myShop.fulfillOrder() << endl;
    cout << "Due amount: $" << myShop.dueAmount() << endl;
    cout << "Cheapest item: " << myShop.cheapestItem() << endl;

    cout << "Drinks: ";
    for (const auto& drink : myShop.drinksOnly()) cout << drink << " ";
    cout << endl;

    cout << "Food: ";
    for (const auto& food : myShop.foodOnly()) cout << food << " ";
    cout << endl;

    return 0;
}
