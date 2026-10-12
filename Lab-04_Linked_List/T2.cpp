#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* next;
};

Node* head = NULL;

void addPatient(int id) {
    Node* n = new Node;
    n->id = id;
    n->next = NULL;

    if (head == NULL) {
        head = n;
    } else {
        Node* t = head;

        while (t->next != NULL) {
            t = t->next;
        }

        t->next = n;
    }
}

void display() {
    Node* t = head;

    cout << "Waiting Patients:\n";

    if (t == NULL) {
        cout << "Queue is empty\n";
        return;
    }

    while (t != NULL) {
        cout << "P" << t->id;

        if (t->next != NULL)
            cout << " -> ";

        t = t->next;
    }

    cout << endl;
}

void servePatient() {
    if (head == NULL) {
        cout << "No patients waiting\n";
        return;
    }

    Node* t = head;

    cout << "Patient P" << t->id << " is being served.\n";

    head = head->next;
    delete t;
}

int main() {
    int n, id;

    cout << "Enter number of patients: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter Patient ID: ";
        cin >> id;
        addPatient(id);
    }

    display();

    servePatient();

    cout << "\nUpdated Queue:\n";
    display();

    return 0;
}