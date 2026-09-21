#include <iostream>
using namespace std;

int main()
{
    int arr[2][2][2] =
    {
        {
            {10, 20},
            {30, 40}
        },
        {
            {50, 60},
            {70, 80}
        }
    };

    cout << "3D Array:\n\n";

    for (int i = 0; i < 2; i++)
    {
        cout << "Layer " << i + 1 << ":\n";

        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                cout << arr[i][j][k] << " ";
            }

            cout << endl;
        }

        cout << endl;
    }

    int search;
    cout << "Searching for: ";
    cin >> search;

    bool found = false;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                if (arr[i][j][k] == search)
                {
                    cout << "\nElement found!\n";
                    cout << "Layer: " << i + 1 << endl;
                    cout << "Row: " << j + 1 << endl;
                    cout << "Column: " << k + 1 << endl;

                    found = true;
                }
            }
        }
    }

    if (found == false)
    {
        cout << "\nElement not found!" << endl;
    }

    return 0;
}