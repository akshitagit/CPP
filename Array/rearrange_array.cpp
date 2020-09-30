#include <iostream>

using namespace std;

int main()
{
    int A;
    cout << "Input array length: ";
    cin >> A;
    int arr[A];

    for (int i = 0; i < A; i++)
    {
        cin >> arr[i];
    }
    
    // [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
    // if i is even, A[i]>=A[i-1]
    // if i is odd, A[i]<=A[i-1]

    for (auto i : arr) cout << i << ' ';
    

    for (int i = 1; i < A; i++)
    {
        if (i % 2 == 0 && arr[i] < arr[i - 1])
        {
            int aux = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = aux;
        }
        else if (i % 2 != 0 && arr[i] >= arr[i - 1])
        {
            int aux = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = aux;
        }
    }
    cout << endl;
    for (auto i : arr) cout << i << ' ';
}
