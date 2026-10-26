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

    void preorder(Node* p)
    {
        if (p == NULL)
            return;

        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }

    void postorder(Node* p)
    {
        if (p == NULL)
            return;

        postorder(p->left);
        postorder(p->right);
        cout << p->data << " ";
    }
};

int main()
{
    BST t;

    int a[] = {40, 20, 60, 10, 30, 50, 70};

    for (int i = 0; i < 7; i++)
        t.root = t.insert(t.root, a[i]);

    cout << "In-order Traversal: ";
    t.inorder(t.root);

    cout << endl;

    cout << "Pre-order Traversal: ";
    t.preorder(t.root);

    cout << endl;

    cout << "Post-order Traversal: ";
    t.postorder(t.root);

    return 0;
}