#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    Node* left;
    Node* right;

    Node(string n)
    {
        name = n;
        left = NULL;
        right = NULL;
    }
};

class Tree
{
public:
    Node* root;

    Tree()
    {
        root = NULL;
    }

    void display(Node* p)
    {
        if (p == NULL)
            return;

        cout << "Person: " << p->name << endl;

        if (p->left != NULL)
            cout << "Left Child: " << p->left->name << endl;
        else
            cout << "Left Child: None" << endl;

        if (p->right != NULL)
            cout << "Right Child: " << p->right->name << endl;
        else
            cout << "Right Child: None" << endl;

        cout << endl;

        display(p->left);
        display(p->right);
    }
};

int main()
{
    Tree t;

    t.root = new Node("Grandfather");

    t.root->left = new Node("Father");
    t.root->right = new Node("Uncle");

    t.root->left->left = new Node("Brother");
    t.root->left->right = new Node("Sister");

    t.root->right->left = new Node("Cousin1");
    t.root->right->right = new Node("Cousin2");

    cout << "Family Tree:" << endl;
    t.display(t.root);

    return 0;
}