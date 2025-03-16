#include <iostream>
using namespace std;

class Books {
protected:
    string genre;
public:
    Books(string g) : genre(g) {}

    void displayGenre() {
        cout << "Genre: " << genre << endl;
    }
};
class Novel : public Books {
private:
    string title, author;
public:
    Novel(string t, string a) : Books("Novel"), title(t), author(a) {}

    void displayDetails() {
        displayGenre();
        cout << "Title: " << title << ", Author: " << author << endl;
    }
};
class Mystery : public Books {
private:
    string title, author;
public:
    Mystery(string t, string a) : Books("Mystery"), title(t), author(a) {}

    void displayDetails() {
        displayGenre();
        cout << "Title: " << title << ", Author: " << author << endl;
    }
};

int main() {
    Novel novel1("Too good to know", "Prajakta kholi");
    Mystery mystery1("Atomic habbits", "James clear");

    cout << "Library Books:\n";
    novel1.displayDetails();
    cout << endl;
    mystery1.displayDetails();

    return 0;
}

