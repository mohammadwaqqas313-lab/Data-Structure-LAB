#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int rollNo;
    Node* next;

    Node(int roll)
    {
        rollNo = roll;
        next = NULL;
    }
};

// Linked List class
class Course
{
private:
    Node* head;

public:

    // Constructor
    Course()
    {
        head = NULL;
    }

    // 1. Add a student at the end
    void addStudent(int rollNo)
    {
        Node* newNode = new Node(rollNo);

        // If list is empty
        if (head == NULL)
        {
            head = newNode;
            return;
        }

        // Go to the last node
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // 2. Insert a student at the beginning
    void insertAtBeginning(int rollNo)
    {
        Node* newNode = new Node(rollNo);

        newNode->next = head;
        head = newNode;
    }

    // 3. Search for a student's Roll Number
    void searchStudent(int rollNo)
    {
        Node* temp = head;

        while (temp != NULL)
        {
            if (temp->rollNo == rollNo)
            {
                cout << "Student with Roll Number "
                     << rollNo << " found." << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Student with Roll Number "
             << rollNo << " not found." << endl;
    }

    // 4. Display all students
    void displayStudents()
    {
        Node* temp = head;

        if (head == NULL)
        {
            cout << "No students enrolled." << endl;
            return;
        }

        cout << "Enrolled Students: ";

        while (temp != NULL)
        {
            cout << temp->rollNo;

            if (temp->next != NULL)
                cout << " -> ";

            temp = temp->next;
        }

        cout << endl;
    }
};


int main()
{
    Course course;

    // Initially:
    // 22 -> 35 -> 41 -> 56

    course.addStudent(22);
    course.addStudent(35);
    course.addStudent(41);
    course.addStudent(56);

    cout << "Initial List:" << endl;
    course.displayStudents();

    // New student Roll Number 18
    cout << "\nAfter inserting Roll Number 18 at beginning:" << endl;

    course.insertAtBeginning(18);

    course.displayStudents();

    // Search
    cout << "\nSearching for Roll Number 41:" << endl;
    course.searchStudent(41);

    cout << "\nSearching for Roll Number 50:" << endl;
    course.searchStudent(50);

    return 0;
}