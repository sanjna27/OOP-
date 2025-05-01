#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct User {
    string user_id, first_name, last_name, address, email;
};

struct Product {
    string product_id, product_name, description;
    int price;
};

struct Order {
    string order_id, user_id, product_id;
    int total_paid;
};

void writeDummyData() {
    ofstream users("users.txt"), products("products.txt"), orders("orders.txt");

    users << "u1,Linus,Torvalds,Finland,linus@example.com\n";
    users << "u2,Bill,Gates,USA,bill@example.com\n";

    products << "p1,Laptop,High-end Linux laptop,1200\n";
    products << "p2,Mouse,Wireless Mouse,30\n";

    orders << "o1,u1,p1,1200\n";
    orders << "o2,u1,p2,30\n";
    orders << "o3,u2,p2,30\n";

    users.close();
    products.close();
    orders.close();
}

void queryProductsForLinus() {
    string user_id;
    ifstream users("users.txt");
    string line;

    while (getline(users, line)) {
        stringstream ss(line);
        string id, fname, lname, addr, email;
        getline(ss, id, ',');
        getline(ss, fname, ',');
        if (fname == "Linus") {
            user_id = id;
            break;
        }
    }
    users.close();
    ifstream orders("orders.txt");
    string product_ids[10];
    int count = 0;
    while (getline(orders, line)) {
        stringstream ss(line);
        string oid, uid, pid, paid;
        getline(ss, oid, ',');
        getline(ss, uid, ',');
        if (uid == user_id) {
            getline(ss, pid, ',');
            product_ids[count++] = pid;
        }
    }
    orders.close();

    ifstream products("products.txt");
    cout << "Products ordered by Linus:\n";
    while (getline(products, line)) {
        stringstream ss(line);
        string pid, pname, desc, price;
        getline(ss, pid, ',');
        for (int i = 0; i < count; ++i) {
            if (pid == product_ids[i]) {
                getline(ss, pname, ',');
                cout << "- " << pname << endl;
                break;
            }
        }
    }
    products.close();
}

int main() {
    writeDummyData();           
    queryProductsForLinus();    
    return 0;
}
