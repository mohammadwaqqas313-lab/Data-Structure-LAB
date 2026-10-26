#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    Node* root;

    BST()
    {
        root = NULL;
    }

    Node* insert(Node* p, int x)
    {
        if (p == NULL)
            return new Node(x);

        if (x < p->data)
            p->left = insert(p->left, x);
        else if (x > p->data)
            p->right = insert(p->right, x);

        return p;
    }

    bool search(int x, int& count)
    {
        Node* p = root;

        while (p != NULL)
        {
            count++;

            if (x == p->data)
                return true;

            if (x < p->data)
                p = p->left;
            else
                p = p->right;
        }

        return false;
    }
};

int main()
{
    BST t;

    int a[] = {40, 20, 60, 10, 30, 50, 70};

    for (int i = 0; i < 7; i++)
        t.root = t.insert(t.root, a[i]);

    int id;
    int count = 0;

    cout << "Enter Book ID to search: ";
    cin >> id;

    if (t.search(id, count))
        cout << "Book Found" << endl;
    else
        cout << "Book Not Found" << endl;

    cout << "Number of Comparisons: " << count << endl;

    return 0;
}