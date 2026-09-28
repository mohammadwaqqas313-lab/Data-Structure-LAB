#include <iostream>
using namespace std;

// Node class: stores one student's roll number
class Node {
public:
    int rollNumber;
    Node* next;

    Node(int roll) {
        rollNumber = roll;
        next = nullptr;
    }
};

// LinkedList class: manages the registered students
class StudentList {
private:
    Node* head;

public:
    StudentList() {
        head = nullptr;
    }

    // 1 & 2. Add a new student (roll number) at the end of the list
    void addStudent(int roll) {
        Node* newNode = new Node(roll);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // 3. Display all registered students
    void display() {
        cout << "Registered Students:" << endl;

        if (head == nullptr) {
            cout << "No students registered yet." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->rollNumber;
            if (temp->next != nullptr) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    // 4. Search for a student using the roll number
    bool search(int roll) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->rollNumber == roll) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // Free memory
    ~StudentList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    StudentList students;

    // Register students
    students.addStudent(101);
    students.addStudent(105);
    students.addStudent(108);
    students.addStudent(112);

    // Display all registered students
    students.display();

    // Search by roll number
    int roll;
    cout << "\nEnter Roll Number to Search: ";
    cin >> roll;

    if (students.search(roll)) {
        cout << "Student Found" << endl;
    } else {
        cout << "Student Not Found" << endl;
    }

    return 0;
}