#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void addTask(const string& taskDesc) {
    ofstream outFile("tasks.txt", ios::app); 
    if (outFile.is_open()) {
        outFile << taskDesc << " | not done\n"; 
        outFile.close();
        cout << "Task added successfully.\n";
    } else {
        cout << "Unable to open file.\n";
    }
}

void viewTasks() {
    ifstream inFile("tasks.txt");
    string line;

    if (inFile.is_open()) {
        int taskNum = 1;
        while (getline(inFile, line)) {
            cout << taskNum++ << ". " << line << endl;
        }
        inFile.close();
    } else {
        cout << "Unable to open file.\n";
    }
}

void markTaskAsDone(int taskNum) {
    ifstream inFile("tasks.txt");
    ofstream tempFile("temp.txt");
    string line;
    int currentTaskNum = 1;

    if (inFile.is_open() && tempFile.is_open()) {
        while (getline(inFile, line)) {
            size_t pos = line.find(" | not done");
            if (pos != string::npos && currentTaskNum == taskNum) {
                line.replace(pos, 10, " | done");
            }
            tempFile << line << endl;
            currentTaskNum++;
        }

        inFile.close();
        tempFile.close();

        remove("tasks.txt");
        rename("temp.txt", "tasks.txt");

        cout << "Task marked as done.\n";
    } else {
        cout << "Unable to open file for updating.\n";
    }
}

int main() {
    int choice;
    string taskDesc;
    int taskNum;

    while (true) {
        cout << "\n--- To-Do List App ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Done\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, taskDesc);
                addTask(taskDesc);
                break;
            case 2:
                cout << "\nTasks:\n";
                viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as done: ";
                cin >> taskNum;
                markTaskAsDone(taskNum);
                break;
            case 4:
                cout << "Exiting the app...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
