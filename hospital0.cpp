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

int findPatientIndex(int id){
    for(int i=0;i<patientCount;i++){
        if(patients[i].id==id){
            return i; 
        } 
    }
    return -1 ;
}
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
    if(findPatientIndex(patients[patientCount].id)!=-1){
        cout<<"ID already exists.\n";
        return ; 
    }
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

 void SearchPatients(){
    int id; 
    cout<<"Enter the patient ID to search :"; 
    cin>>id; 
    int pos=findPatientIndex(id); 
    if(pos==-1){
        cout<<"Patient not found!"<<endl; 
    }
    else {
        cout<<patients[pos].id<<"|";
        cout<<patients[pos].name<<"|";
        cout<<patients[pos].age<<"|";
        cout<<patients[pos].disease<<endl; 
    }
 }
 void deletePatient(){
    int id; 
    cout<<"Enter the ID to delete"<<endl; 
    cin>>id; 
    int pos=findPatientIndex(id); 
    if(pos==-1){
        cout<<"Patient not found"<<endl; 
    }
    else{
        for(int i=pos;i<=patientCount-2;i++){
            patients[i]=patients[i+1];  
        }
        patientCount--;
        cout<<"Patient deleted!"<<endl; 
    }
 }

int main() {
    int choice;
    do {
        cout << "\n1. Add Patient\n2. View Patients\n3. SearchPatient\n4. DeletePatient\n0. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) addPatient();
        else if (choice == 2) viewPatients();
        else if(choice==3) SearchPatients();
        else if(choice==4) deletePatient(); 
    } while (choice != 0);
    return 0;
}