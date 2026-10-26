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

    void inorder(Node* p)
    {
        if (p == NULL)
            return;

        inorder(p->left);
        cout << p->data << " ";
        inorder(p->right);
    }
};

int main()
{
    BST t;

    int a[] = {45, 25, 65, 15, 35, 55, 75};

    for (int i = 0; i < 7; i++)
        t.root = t.insert(t.root, a[i]);

    int x;

    for (int i = 0; i < 2; i++)
    {
        cout << "Enter roll number: ";
        cin >> x;

        t.root = t.insert(t.root, x);
    }

    cout << "Roll Numbers in Ascending Order: ";
    t.inorder(t.root);

    return 0;
}