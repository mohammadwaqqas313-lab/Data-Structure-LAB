#include <iostream>
#include <string>
using namespace std;

class Stack {
    string actions[10];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(string action) {
        if (top == 9) {
            cout << "Stack is full\n";
        } else {
            actions[++top] = action;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty\n";
        } else {
            cout << "Undo: " << actions[top--] << endl;
        }
    }

    void display() {
        if (top == -1) {
            cout << "No actions remaining\n";
        } else {
            for (int i = top; i >= 0; i--) {
                cout << actions[i] << endl;
            }
        }
    }

    void showTop() {
        if (top == -1) {
            cout << "No current action\n";
        } else {
            cout << "Current TOP action: " << actions[top] << endl;
        }
    }
};

int main() {
    Stack s;

    s.push("Type Hello");
    s.push("Type World");
    s.push("Add !");
    s.push("Delete !");

    cout << "Actions (TOP to bottom):\n";
    s.display();

    cout << "\nPerforming two Undo operations:\n";
    s.pop();
    s.pop();

    s.showTop();

    cout << "\nRemaining actions:\n";
    s.display();

    return 0;
}