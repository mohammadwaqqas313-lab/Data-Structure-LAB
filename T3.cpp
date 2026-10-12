#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string id;
    Node* next;

    Node(string x) {
        id = x;
        next = NULL;
    }
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    void push(string id) {
        Node* n = new Node(id);
        n->next = top;
        top = n;
    }

    void pop() {
        if (top == NULL) {
            cout << "Stack is empty\n";
        } else {
            Node* temp = top;
            cout << "Handled request: " << top->id << endl;
            top = top->next;
            delete temp;
        }
    }

    void showTop() {
        if (top == NULL) {
            cout << "No requests remaining\n";
        } else {
            cout << "Current TOP request: " << top->id << endl;
        }
    }

    void display() {
        if (top == NULL) {
            cout << "No requests remaining\n";
        } else {
            Node* temp = top;

            while (temp != NULL) {
                cout << temp->id << endl;
                temp = temp->next;
            }
        }
    }

    ~Stack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack s;

    s.push("P101");
    s.push("P102");
    s.push("P103");
    s.push("P104");

    cout << "Requests (TOP to bottom):\n";
    s.display();

    cout << "\nHandling latest request:\n";
    s.pop();

    s.showTop();

    cout << "\nRemaining requests:\n";
    s.display();

    return 0;
}