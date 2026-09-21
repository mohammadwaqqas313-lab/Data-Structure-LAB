#include <iostream>
using namespace std;

int main()
{
    int computers[2][3][5] =
    {
        {
            {1, 0, 1, 0, 1},
            {0, 1, 0, 1, 0},
            {1, 1, 0, 0, 1}
        },
        {
            {0, 1, 1, 0, 1},
            {1, 0, 0, 1, 0},
            {1, 1, 1, 0, 0}
        }
    };

    int available = 0;
    int inUse = 0;

    cout << "Computer Lab Status:\n";

    for (int i = 0; i < 2; i++)
    {
        cout << "\nLab " << i + 1 << ":\n";

        for (int j = 0; j < 3; j++)
        {
            cout << "Row " << j + 1 << ": ";

            for (int k = 0; k < 5; k++)
            {
                cout << computers[i][j][k] << " ";

                if (computers[i][j][k] == 0)
                    available++;
                else
                    inUse++;
            }

            cout << endl;
        }
    }
    cout << "\nTotal Available Computers = " << available << endl;
    cout << "Total Computers In Use = " << inUse << endl;
    cout << "\nAvailable Computers in Each Lab:\n";
    for (int i = 0; i < 2; i++)
    {
        int count = 0;

        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (computers[i][j][k] == 0)
                {
                    count++;
                }
            }
        }

        cout << "Lab " << i + 1 << " = " << count << endl;
    }

    int lab, row, computer;

    cout << "\nEnter lab number (1-2): ";
    cin >> lab;

    cout << "Enter row number (1-3): ";
    cin >> row;

    cout << "Enter computer number (1-5): ";
    cin >> computer;

    if (computers[lab - 1][row - 1][computer - 1] == 0)
    {
        cout << "Selected computer is Available." << endl;
    }
    else
    {
        cout << "Selected computer is In Use." << endl;
    }

    return 0;
}