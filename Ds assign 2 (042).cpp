#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Patient {
    string name;
    string condition;
    int priority;

    Patient(string n, string c, int p) : name(n), condition(c), priority(p) {}
};

// Comparator for the priority_queue (lower number = higher priority)
struct ComparePriority {
    bool operator()(const Patient& a, const Patient& b) {
        return a.priority > b.priority;
    }
};

int determinePriority(const string& condition) {
    if (condition == "Heart Attack" || condition == "Stroke") return 1;
    if (condition == "Severe Burn" || condition == "Broken Leg") return 2;
    if (condition == "Fever" || condition == "Food Poisoning") return 3;
    return 4; // Default for less critical cases
}

int main() {
    priority_queue<Patient, vector<Patient>, ComparePriority> emergencyQueue;
    int option;
    string name, condition;

    while (true) {
        cout << "\n--- Emergency Room System ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Treat Patient\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> option;
        cin.ignore();

        if (option == 1) {
            cout << "Patient's Name: ";
            getline(cin, name);
            cout << "Condition: ";
            getline(cin, condition);

            int priority = determinePriority(condition);
            emergencyQueue.push(Patient(name, condition, priority));
            cout << "Patient added to the queue with priority " << priority << ".\n";
        } else if (option == 2) {
            if (!emergencyQueue.empty()) {
                Patient current = emergencyQueue.top();
                emergencyQueue.pop();
                cout << "\nNow treating:\n";
                cout << "Name     : " << current.name << endl;
                cout << "Condition: " << current.condition << endl;
                cout << "Priority : " << current.priority << endl;
            } else {
                cout << "No patients to treat.\n";
            }
        } else if (option == 3) {
            cout << "Goodbye! Stay safe.\n";
            break;
        } else {
            cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
