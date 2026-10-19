#include <iostream>
using namespace std;

class Stack {
    string pages[10];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(string page) {
        if (top == 9) {
            cout << "Stack is full\n";
        } else {
            pages[++top] = page;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack is empty\n";
        } else {
            cout << "Back from: " << pages[top--] << endl;
        }
    }

    void display() {
        if (top == -1) {
            cout << "No pages in history\n";
        } else {
            for (int i = top; i >= 0; i--) {
                cout << pages[i] << endl;
            }
        }
    }

    void showTop() {
        if (top == -1) {
            cout << "No current page\n";
        } else {
            cout << "Current TOP page: " << pages[top] << endl;
        }
    }
};

int main() {
    Stack s;

    s.push("Google");
    s.push("YouTube");
    s.push("Facebook");
    s.push("GitHub");

    cout << "Browsing history (TOP to bottom):\n";
    s.display();

    cout << "\nPress Back:\n";
    s.pop();

    s.showTop();

    cout << "\nRemaining history:\n";
    s.display();

    return 0;
}