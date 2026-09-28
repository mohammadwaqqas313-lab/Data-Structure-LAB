#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* next;
};

Node* head = NULL;

void addProduct(int id) {
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

    if (t == NULL) {
        cout << "Cart is empty\n";
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

void removeProduct(int id) {
    Node* t = head;
    Node* prev = NULL;

    while (t != NULL) {
        if (t->id == id) {
            if (prev == NULL) {
                head = t->next;
            } else {
                prev->next = t->next;
            }

            delete t;

            cout << "Product Removed\n";
            return;
        }

        prev = t;
        t = t->next;
    }

    cout << "Product Not Found\n";
}

int main() {
    int n, id;

    cout << "Enter number of products: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter Product ID: ";
        cin >> id;
        addProduct(id);
    }

    cout << "\nShopping Cart:\n";
    display();

    cout << "\nEnter Product ID to Remove: ";
    cin >> id;

    removeProduct(id);

    cout << "\nUpdated Cart:\n";
    display();

    return 0;
}