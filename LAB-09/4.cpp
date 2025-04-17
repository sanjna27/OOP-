#include <iostream>
using namespace std;

class Passenger; 

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int totalSeats;
    int bookedSeats;

    string passengerIDs[100];
    string seatClass[100];

public:
    Flight(string fn, string dep, string arr, int seats)
        : flightNumber(fn), departure(dep), arrival(arr), totalSeats(seats), bookedSeats(0) {}

    bool bookSeat(const Passenger& p, const string& sClass);
    bool cancelSeat(const Passenger& p);
    bool upgradeSeat(const Passenger& p);
    void showFlightStatus() const;
    bool isBooked(const Passenger& p) const;
};

class Passenger {
private:
    string id;
    string name;

public:
    Passenger(string pid, string pname) : id(pid), name(pname) {}

    string getID() const { return id; }
    string getName() const { return name; }

    void requestBooking(Flight& flight, const string& sClass) {
        cout << "\n" << name << " requesting booking (" << sClass << ")...\n";
        if (!flight.bookSeat(*this, sClass)) {
            cout << "Booking failed.\n";
        }
    }

    void requestCancellation(Flight& flight) {
        cout << "\n" << name << " requesting cancellation...\n";
        if (!flight.cancelSeat(*this)) {
            cout << "Cancellation failed.\n";
        }
    }

    void requestUpgrade(Flight& flight) {
        cout << "\n" << name << " requesting upgrade...\n";
        if (!flight.upgradeSeat(*this)) {
            cout << "Upgrade failed.\n";
        }
    }
};

bool Flight::isBooked(const Passenger& p) const {
    for (int i = 0; i < bookedSeats; i++) {
        if (passengerIDs[i] == p.getID()) {
            return true;
        }
    }
    return false;
}

bool Flight::bookSeat(const Passenger& p, const string& sClass) {
    if (bookedSeats >= totalSeats) {
        cout << "Flight is full.\n";
        return false;
    }

    if (isBooked(p)) {
        cout << "Passenger already booked.\n";
        return false;
    }

    passengerIDs[bookedSeats] = p.getID();
    seatClass[bookedSeats] = sClass;
    bookedSeats++;

    cout << "Seat booked successfully for " << p.getName() << " in " << sClass << " class.\n";
    return true;
}

bool Flight::cancelSeat(const Passenger& p) {
    for (int i = 0; i < bookedSeats; i++) {
        if (passengerIDs[i] == p.getID()) {
            for (int j = i; j < bookedSeats - 1; j++) {
                passengerIDs[j] = passengerIDs[j + 1];
                seatClass[j] = seatClass[j + 1];
            }
            bookedSeats--;
            cout << "Seat cancelled for " << p.getName() << ".\n";
            return true;
        }
    }

    cout << "Passenger has no booking.\n";
    return false;
}

bool Flight::upgradeSeat(const Passenger& p) {
    for (int i = 0; i < bookedSeats; i++) {
        if (passengerIDs[i] == p.getID()) {
            if (seatClass[i] == "Business") {
                cout << "Already in Business class.\n";
                return false;
            }

            seatClass[i] = "Business";
            cout << p.getName() << " upgraded to Business class.\n";
            return true;
        }
    }

    cout << "Passenger has no booking to upgrade.\n";
    return false;
}

void Flight::showFlightStatus() const {
    cout << "\nFlight " << flightNumber << " [" << departure << " -> " << arrival << "]\n";
    cout << "Total Seats: " << totalSeats << ", Booked: " << bookedSeats << "\n";
    cout << "Passenger List:\n";

    for (int i = 0; i < bookedSeats; i++) {
        cout << "  ID: " << passengerIDs[i] << " | Class: " << seatClass[i] << "\n";
    }
}

int main() {
    Flight flight1("PK101", "Ghotki", "Karachi", 2);

    Passenger p1("P001", "Sanjna");
    Passenger p2("P002", "Anshu");
    Passenger p3("P003", "Ansh");

    p1.requestBooking(flight1, "Economy");
    p2.requestBooking(flight1, "Economy");
    p3.requestBooking(flight1, "Economy");

    p1.requestUpgrade(flight1);
    p2.requestCancellation(flight1);
    p3.requestBooking(flight1, "Economy"); 

    flight1.showFlightStatus();

    return 0;
}
