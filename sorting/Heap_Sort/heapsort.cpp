#include <iostream>
#include <iomanip>

void heapify(int arr[], const int n, const int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if(left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if(right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if(largest != root)
    {
        std::swap(arr[root], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], const int n)
{
    for(int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for(int i = n - 1; i >= 0; i--)
    {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void print(const int arr[], const int n)
{
    for(int i = 0; i < n; ++i)
    {
        std::cout << std::setw(3) << arr[i];
    }
    std::cout << "\n";
}

int main()
{
    int arr[] = {8, 4, 3, 7, 10, 9, 1, 2, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    print(arr, n);
    heapSort(arr, n);
    print(arr, n);
}