#include <iostream>
#include <vector>
#include <cstdlib>  // For stoi()
using namespace std;

struct Person {
    int ID;
    string Name;
};

void SortID(vector<Person>& People) {
    int Size = People.size();
    for (int i = 0; i < Size - 1; i++) {
        for (int j = 0; j < Size - i - 1; j++) {
            if (People[j].ID > People[j + 1].ID) {
                swap(People[j], People[j + 1]);
            }
        }
    }
}

void SortName(vector<Person>& People) {
    int Size = People.size();
    for (int i = 0; i < Size - 1; i++) {
        for (int j = 0; j < Size - i - 1; j++) {
            if (People[j].Name > People[j + 1].Name) {  
                swap(People[j], People[j + 1]);
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Error: Missing arguments. Provide N followed by N pairs of ID and Name." << endl;
        return 1;
    }

    int N;
    try {
        N = stoi(argv[1]);
    } catch (...) {
        cout << "Error: First argument must be an integer (N)." << endl;
        return 1;
    }

    if (argc != (2 + N * 2)) {
        cout << "Error: Invalid number of arguments. Expected " << (2 + N * 2) << " arguments." << endl;
        return 1;
    }

    vector<Person> People;

    for (int i = 0; i < N; i++) {
        Person Info;
        try {
            Info.ID = stoi(argv[2 + 2 * i]);
        } catch (...) {
            cout << "Error: ID must be an integer." << endl;
            return 1;
        }
        Info.Name = argv[2 + 2 * i + 1];
        People.push_back(Info);
    }

    // Sort by ID
    SortID(People);
    cout << "Sorted by ID:" << endl;
    for (const auto& Info : People) {
        cout << "ID: " << Info.ID << ", Name: " << Info.Name << endl;
    }

    // Sort by Name
    SortName(People);
    cout << "\nSorted by Name:" << endl;
    for (const auto& Info : People) {
        cout << "ID: " << Info.ID << ", Name: " << Info.Name << endl;
    }

    return 0;
}
