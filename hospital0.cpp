#include <iostream>
#include <string>
using namespace std;

// One patient's record: four pieces of data grouped together
struct Patient {
    int id;
    string name;
    int age;
    string disease;
};

// Global array and counter, so every function can use them
Patient patients[100];   // room for 100 patients
int patientCount = 0;    // how many patients are actually stored

void addPatient() {
    // Stop if the array is full
    if (patientCount >= 100) {
        cout << "Patient list is full.\n";
        return;
    }

    // Read into the next free box: patients[patientCount]
    cout << "Enter ID: ";
    cin >> patients[patientCount].id;
    cin.ignore();   // remove leftover Enter before getline

    cout << "Enter name: ";
    getline(cin, patients[patientCount].name);

    cout << "Enter age: ";
    cin >> patients[patientCount].age;
    cin.ignore();   // remove leftover Enter before getline

    cout << "Enter disease: ";
    getline(cin, patients[patientCount].disease);

    patientCount++;   // only now move to the next free box
    cout << "Patient added!\n";
}

void viewPatients() {
    if (patientCount == 0) {
        cout << "No patients yet.\n";
        return;
    }

    // Loop only up to patientCount, not 100
    for (int i = 0; i < patientCount; i++) {
        cout << patients[i].id << " | "
             << patients[i].name << " | "
             << patients[i].age << " | "
             << patients[i].disease << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Patient\n2. View Patients\n0. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) addPatient();
        else if (choice == 2) viewPatients();
    } while (choice != 0);
    return 0;
}