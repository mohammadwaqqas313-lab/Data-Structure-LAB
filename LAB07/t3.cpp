
#include <iostream>
using namespace std;

const int SIZE = 5;

struct Patient
{
    string id;
    int priority;
};

Patient q[SIZE];
int count = 0;

void enqueue(string id, int priority)
{
    if (count == SIZE)
    {
        cout << "Queue is full!\n";
        return;
    }

    int i = count - 1;

    while (i >= 0 && q[i].priority > priority)
    {
        q[i + 1] = q[i];
        i--;
    }

    q[i + 1].id = id;
    q[i + 1].priority = priority;
    count++;

    cout << "Patient added successfully.\n";
}

void dequeue()
{
    if (count == 0)
    {
        cout << "No patients waiting.\n";
        return;
    }

    cout << "Treating Patient: " << q[0].id << endl;
    cout << "Priority: " << q[0].priority << endl;

    for (int i = 0; i < count - 1; i++)
        q[i] = q[i + 1];

    count--;
}

void display()
{
    if (count == 0)
    {
        cout << "No patients waiting.\n";
        return;
    }

    cout << "\nWaiting Patients:\n";

    for (int i = 0; i < count; i++)
    {
        cout << "Patient ID: " << q[i].id
             << ", Priority: " << q[i].priority << endl;
    }
}

int main()
{
    int choice, priority;
    string id;

    do
    {
        cout << "\n--- Hospital Emergency Department ---\n";
        cout << "1. Add Patient\n";
        cout << "2. Treat Patient\n";
        cout << "3. Display Waiting Patients\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter patient ID: ";
                cin >> id;

                cout << "Enter priority (1 = highest): ";
                cin >> priority;

                if (priority < 1)
                {
                    cout << "Invalid priority!\n";
                    break;
                }

                enqueue(id, priority);
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
