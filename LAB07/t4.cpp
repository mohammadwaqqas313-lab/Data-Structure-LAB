
#include <iostream>
using namespace std;

const int SIZE = 5;

int q[SIZE];
int front = -1, rear = -1;

bool isFull()
{
    return (front == 0 && rear == SIZE - 1) ||
           (front == rear + 1);
}

bool isEmpty()
{
    return front == -1;
}

void insertFront(int id)
{
    if (isFull())
    {
        cout << "Deque is full!\n";
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else if (front == 0)
    {
        front = SIZE - 1;
    }
    else
    {
        front--;
    }

    q[front] = id;
    cout << "Request inserted at front.\n";
}

void insertRear(int id)
{
    if (isFull())
    {
        cout << "Deque is full!\n";
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else if (rear == SIZE - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    q[rear] = id;
    cout << "Request inserted at rear.\n";
}

void deleteFront()
{
    if (isEmpty())
    {
        cout << "Deque is empty!\n";
        return;
    }

    cout << "Removed request: " << q[front] << endl;

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == SIZE - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void deleteRear()
{
    if (isEmpty())
    {
        cout << "Deque is empty!\n";
        return;
    }

    cout << "Removed request: " << q[rear] << endl;

    if (front == rear)
    {
        front = rear = -1;
    }
    else if (rear == 0)
    {
        rear = SIZE - 1;
    }
    else
    {
        rear--;
    }
}

void display()
{
    if (isEmpty())
    {
        cout << "Deque is empty!\n";
        return;
    }

    cout << "Requests from front to rear: ";

    int i = front;

    while (true)
    {
        cout << q[i] << " ";

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    cout << endl;
}

int main()
{
    int choice, id;

    do
    {
        cout << "\n--- Passenger Request Management ---\n";
        cout << "1. Insert at Front\n";
        cout << "2. Insert at Rear\n";
        cout << "3. Remove from Front\n";
        cout << "4. Remove from Rear\n";
        cout << "5. Display Requests\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter request ID: ";
                cin >> id;
                insertFront(id);
                break;

            case 2:
                cout << "Enter request ID: ";
                cin >> id;
                insertRear(id);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
