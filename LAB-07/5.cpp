#include <iostream>
using namespace std;

// Base class
class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
public:
    Media(string t, string pDate, string uID, string pub)
        : title(t), publicationDate(pDate), uniqueID(uID), publisher(pub) {}

    virtual void displayInfo() {
        cout << "Title: " << title << "\nPublication Date: " << publicationDate
             << "\nUnique ID: " << uniqueID << "\nPublisher: " << publisher << endl;
    }

    void checkOut() {
        cout << title << " has been checked out!\n";
    }

    void returnItem() {
        cout << title << " has been returned!\n";
    }
};

// Derived Book class
class Book : public Media {
private:
    string author, ISBN;
    int numberOfPages;
public:
    Book(string t, string pDate, string uID, string pub, string a, string isbn, int pages)
        : Media(t, pDate, uID, pub), author(a), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << "\nISBN: " << ISBN
             << "\nPages: " << numberOfPages << endl;
    }
};

// Derived DVD class
class DVD : public Media {
private:
    string director;
    int duration;
    double rating;
public:
    DVD(string t, string pDate, string uID, string pub, string d, int dur, double r)
        : Media(t, pDate, uID, pub), director(d), duration(dur), rating(r) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << "\nDuration: " << duration
             << " min\nRating: " << rating << "/10\n";
    }
};

// Derived CD class
class CD : public Media {
private:
    string artist, genre;
    int numberOfTracks;
public:
    CD(string t, string pDate, string uID, string pub, string art, int tracks, string g)
        : Media(t, pDate, uID, pub), artist(art), numberOfTracks(tracks), genre(g) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << "\nTracks: " << numberOfTracks
             << "\nGenre: " << genre << endl;
    }
};

// Function Overloading for Searching
void searchMedia(string title) {
    cout << "Searching for media with title: " << title << endl;
}

void searchMedia(string author, int year) {
    cout << "Searching for media by " << author << " published in " << year << endl;
}

void searchMedia(int year) {
    cout << "Searching for media published in year: " << year << endl;
}

// Main function
int main() {
    Book b("C++ Guide", "2023", "B001", "Tech Press", "John Doe", "123456789", 450);
    DVD d("Inception", "2010", "D002", "Warner Bros", "Christopher Nolan", 148, 8.8);
    CD c("Greatest Hits", "2005", "C003", "Sony Music", "The Beatles", 12, "Rock");

    cout << "----- Library Items -----\n";
    b.displayInfo();
    cout << "----------------------\n";
    d.displayInfo();
    cout << "----------------------\n";
    c.displayInfo();

    cout << "\n----- Checking Out & Returning Items -----\n";
    b.checkOut();
    d.returnItem();

    cout << "\n----- Searching Media -----\n";
    searchMedia("C++ Guide");
    searchMedia("John Doe", 2023);
    searchMedia(2010);

    return 0;
}
