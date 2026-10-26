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

    Node* findMin(Node* p)
    {
        while (p->left != NULL)
            p = p->left;

        return p;
    }

    Node* deleteNode(Node* p, int x)
    {
        if (p == NULL)
            return NULL;

        if (x < p->data)
        {
            p->left = deleteNode(p->left, x);
        }
        else if (x > p->data)
        {
            p->right = deleteNode(p->right, x);
        }
        else
        {
            if (p->left == NULL)
            {
                Node* temp = p->right;
                delete p;
                return temp;
            }

            if (p->right == NULL)
            {
                Node* temp = p->left;
                delete p;
                return temp;
            }

            Node* temp = findMin(p->right);

            p->data = temp->data;

            p->right = deleteNode(p->right, temp->data);
        }

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

    int a[] = {50, 30, 70, 20, 40, 60, 80};

    for (int i = 0; i < 7; i++)
        t.root = t.insert(t.root, a[i]);

    int id;

    cout << "Enter Employee ID to delete: ";
    cin >> id;

    t.root = t.deleteNode(t.root, id);

    cout << "Remaining Employee IDs: ";
    t.inorder(t.root);

    return 0;
}