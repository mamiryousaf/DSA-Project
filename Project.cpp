#include <iostream>
using namespace std;

struct Patient {
    int id;
    string name;
    int age;
    Patient* next;
};
Patient* head = NULL;

struct Stack {
    int id;
    Stack* next;
};
Stack* top = NULL;

struct Queue {
    int id;
    Queue* next;
};
Queue* front = NULL;
Queue* rear = NULL;

int wardBeds[5] = {0, 0, 0, 0, 0};

void addPatient() {
    Patient* p = new Patient();
    cout << "Enter Patient ID: ";
    cin >> p->id;
    cout << "Enter Name: ";
    cin >> p->name;
    cout << "Enter Age: ";
    cin >> p->age;
    p->next = head;
    head = p;
    Stack* s = new Stack();
    s->id = p->id;
    s->next = top;
    top = s;
    cout << "Patient Added Successfully\n";
}

void displayPatients() {
    Patient* temp = head;
    if (!temp) {
        cout << "No Patients Found\n";
        return;
    }
    while (temp) {
        cout << "ID: " << temp->id << " Name: " << temp->name << " Age: " << temp->age << endl;
        temp = temp->next;
    }
}

void undoLastPatient() {
    if (!top) {
        cout << "No Undo Available\n";
        return;
    }
    cout << "Last Patient ID Removed: " << top->id << endl;
    top = top->next;
}

void addAppointment() {
    Queue* q = new Queue();
    cout << "Enter Patient ID for Appointment: ";
    cin >> q->id;
    q->next = NULL;
    if (!rear) {
        front = rear = q;
    } else {
        rear->next = q;
        rear = q;
    }
    cout << "Appointment Added\n";
}

void serveAppointment() {
    if (!front) {
        cout << "No Appointments\n";
        return;
    }
    cout << "Serving Patient ID: " << front->id << endl;
    front = front->next;
}

void allocateBed() {
    for (int i = 0; i < 5; i++) {
        if (wardBeds[i] == 0) {
            wardBeds[i] = 1;
            cout << "Bed " << i + 1 << " Allocated\n";
            return;
        }
    }
    cout << "No Beds Available\n";
}

void showBeds() {
    for (int i = 0; i < 5; i++) {
        cout << "Bed " << i + 1 << ": " << (wardBeds[i] ? "Occupied" : "Free") << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Hospital Management System ---\n";
        cout << "1. Add Patient \n";
        cout << "2. Display Patients\n";
        cout << "3. Undo Last Patient \n";
        cout << "4. Add Appointment \n";
        cout << "5. Serve Appointment\n";
        cout << "6. Allocate Bed \n";
        cout << "7. Show Beds\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addPatient(); break;
            case 2: displayPatients(); break;
            case 3: undoLastPatient(); break;
            case 4: addAppointment(); break;
            case 5: serveAppointment(); break;
            case 6: allocateBed(); break;
            case 7: showBeds(); break;
            case 8: cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice\n";
        }
    } while (choice != 8);
    return 0;
}
