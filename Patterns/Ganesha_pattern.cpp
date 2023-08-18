#include <iostream>
using namespace std;

void printLine(int n, bool isFirst, bool isLast)
{
    cout << "*";
    for (int i = 0; i < n - 2; i++)
        cout << " ";
    cout << "*";

    if (isFirst)
    {
        for (int i = 0; i < n / 2; i++)
            cout << "*";
    }

    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n / 2; i++)
    {
        printLine(n, i == 1, false);
    }

    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    cout << endl;

    for (int i = 0; i < n / 2; i++)
    {
        printLine(n, i == (n / 2) - 1, true);
    }

    return 0;
}
