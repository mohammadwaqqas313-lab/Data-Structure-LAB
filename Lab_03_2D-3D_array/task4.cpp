#include <iostream>
using namespace std;

int main()
{
    int beds[3][3][4] =
    {
        {
            {1, 0, 1, 0},
            {0, 1, 0, 1},
            {1, 1, 0, 0}
        },
        {
            {0, 1, 1, 0},
            {1, 0, 0, 1},
            {1, 1, 1, 0}
        },
        {
            {1, 0, 0, 1},
            {0, 1, 1, 0},
            {1, 0, 1, 1}
        }
    };

    int occupied = 0;
    int available = 0;

    cout << "Hospital Bed Status:\n";

    for (int i = 0; i < 3; i++)
    {
        cout << "\nFloor " << i + 1 << ":\n";

        for (int j = 0; j < 3; j++)
        {
            cout << "Ward " << j + 1 << ": ";

            for (int k = 0; k < 4; k++)
            {
                cout << beds[i][j][k] << " ";

                if (beds[i][j][k] == 1)
                    occupied++;
                else
                    available++;
            }

            cout << endl;
        }
    }

    cout << "\nTotal Occupied Beds = " << occupied << endl;
    cout << "Total Available Beds = " << available << endl;

    cout << "\nOccupied Beds on Each Floor:\n";

    for (int i = 0; i < 3; i++)
    {
        int count = 0;

        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (beds[i][j][k] == 1)
                    count++;
            }
        }

        cout << "Floor " << i + 1 << " = " << count << endl;
    }

    int floor, ward, bed;

    cout << "\nEnter floor number (1-3): ";
    cin >> floor;

    cout << "Enter ward number (1-3): ";
    cin >> ward;

    cout << "Enter bed number (1-4): ";
    cin >> bed;

    if (beds[floor - 1][ward - 1][bed - 1] == 0)
        cout << "Selected bed is Available." << endl;
    else
        cout << "Selected bed is Occupied." << endl;

    return 0;
}