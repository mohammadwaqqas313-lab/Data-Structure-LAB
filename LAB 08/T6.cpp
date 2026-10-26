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
        else
            cout << "Duplicate Product ID!" << endl;

        return p;
    }

    bool search(int x)
    {
        Node* p = root;

        while (p != NULL)
        {
            if (x == p->data)
                return true;

            if (x < p->data)
                p = p->left;
            else
                p = p->right;
        }

        return false;
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

    void destroy(Node* p)
    {
        if (p == NULL)
            return;

        destroy(p->left);
        destroy(p->right);

        delete p;
    }

    ~BST()
    {
        destroy(root);
    }
};

int main()
{
    BST t;

    int choice, id;

    do
    {
        cout << "\n\n===== Online Store Inventory =====" << endl;
        cout << "1. Insert Product ID" << endl;
        cout << "2. Search Product ID" << endl;
        cout << "3. Delete Product ID" << endl;
        cout << "4. In-order Traversal" << endl;
        cout << "5. Pre-order Traversal" << endl;
        cout << "6. Post-order Traversal" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Product ID: ";
            cin >> id;

            t.root = t.insert(t.root, id);

            break;

        case 2:
            cout << "Enter Product ID to search: ";
            cin >> id;

            if (t.search(id))
                cout << "Product Found!" << endl;
            else
                cout << "Product Not Found!" << endl;

            break;

        case 3:
            cout << "Enter Product ID to delete: ";
            cin >> id;

            if (t.search(id))
            {
                t.root = t.deleteNode(t.root, id);
                cout << "Product Deleted!" << endl;
            }
            else
            {
                cout << "Product Not Found!" << endl;
            }

            break;

        case 4:
            cout << "In-order: ";
            t.inorder(t.root);
            cout << endl;

            break;

        case 5:
            cout << "Pre-order: ";
            t.preorder(t.root);
            cout << endl;

            break;

        case 6:
            cout << "Post-order: ";
            t.postorder(t.root);
            cout << endl;

            break;

        case 7:
            cout << "Program Exited!" << endl;

            break;

        default:
            cout << "Invalid Choice!" << endl;
        }

    } while (choice != 7);

    return 0;
}