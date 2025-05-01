#include <iostream>
#include <fstream>
using namespace std;

string encrypt(string text) {
    string encrypted = "";
    for (int i = 0; i < text.length(); i++) {
        encrypted += char(text[i] + (i + 1));
    }
    return encrypted;
}

string decrypt(string text) {
    string decrypted = "";
    for (int i = 0; i < text.length(); i++) {
        decrypted += char(text[i] - (i + 1)); 
    }
    return decrypted;
}

int main() {
    string input;
    cout << "Enter String = ";
    getline(cin, input);

    string encrypted = encrypt(input);
    ofstream fout("encrypted.txt");
    fout << encrypted;
    fout.close();
    cout << "Normal Text:= " << input << endl;
    cout << "Encrypted text inserted in file" << endl;

    ifstream fin("encrypted.txt");
    string fileData;
    getline(fin, fileData);
    fin.close();
    
    string decrypted = decrypt(fileData);
    cout << "Decrypted text Read then decoded from file" << endl;
    cout << decrypted << endl;

    return 0;
}
