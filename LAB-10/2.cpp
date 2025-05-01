#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int id;
    string name;
    string designation;
    int years;
    ofstream fout("employ txt");
    fout << "1 Sanjna Manager 3\n";
    fout << "2 Anshul Developer 1\n";
    fout << "3 Simran Manager 1\n";
    fout << "4 Shobha Analyst 5\n";
    fout << "5 Ajay Manager 4\n";
    fout.close();

    ifstream fin("employ txt");
    ofstream fout2("filtered.txt");

    int newID = 1;

    cout << "Filtered Managers with 2+ years:\n";
    while (fin >> id >> name >> designation >> years) {
        if  (designation == "Manager" && years >= 2) {
            cout << name << " " << designation << " " << years << endl;
            fout2 << newID++ << " " << name << " " << designation << " " <<  years+1 << "\n";
        }
    }

    fin.close();
    fout2.close();

    remove("employ txt");
    rename("filtered.txt", "employ txt");
    return 0;
}
