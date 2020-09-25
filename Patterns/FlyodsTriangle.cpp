#include <iostream>
using namespace std;

int main()
{

    cout << "Enter a number for printing Flyods Triangle:";
    int size;
    cin >> size;
    int num = 1;

    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout <<num++<<" ";
        }
        cout << endl;
    }
    return 0;
}
