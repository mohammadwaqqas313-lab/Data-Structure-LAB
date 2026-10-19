
#include <iostream>
using namespace std;

const int SIZE = 5;

int q[SIZE];
int front = -1, rear = -1;

void enqueue(int packet)
{
    if ((rear + 1) % SIZE == front)
    {
        cout << "Queue Overflow! Queue is full.\n";
        return;
    }

    if (front == -1)
        front = 0;

    rear = (rear + 1) % SIZE;
    q[rear] = packet;

    cout << "Packet " << packet << " added successfully.\n";
}

void dequeue()
{
    if (front == -1)
    {
        cout << "Queue Underflow! No packets available.\n";
        return;
    }

    cout << "Packet " << q[front] << " transmitted.\n";

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

void display()
{
    if (front == -1)
    {
        cout << "No packets waiting for transmission.\n";
        return;
    }

    cout << "Packets waiting for transmission: ";

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
    int choice, packet;

    do
    {
        cout << "\n--- Network Packet Management ---\n";
        cout << "1. Insert Packet\n";
        cout << "2. Transmit Packet\n";
        cout << "3. Display Waiting Packets\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter packet ID: ";
                cin >> packet;
                enqueue(packet);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
