#include <iostream>
using namespace std;

int main()
{
    int arr[50];
    int i, j, desc, n;
    cout << "\nEnter number of elements you want in array: ";
    cin >> n;
    cout << "\nEnter elements in an array:\n";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                desc = arr[i];
                arr[i] = arr[j];
                arr[j] = desc;
            }
        }
    }
    cout << "\nSorted Array in Descending Order: ";
    for (i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
