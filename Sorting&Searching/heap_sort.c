#include <stdio.h>
int arr[50];
void heap_sort(int n);
void heapify(int n, int i);
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int i, n;
    printf("Enter the no of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    heap_sort(n);
    printf("\nSorted list is: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void heap_sort(int n)
{
    int i;
    for (i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);
    for (i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(i, 0);
    }
}

void heapify(int n, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(n, largest);
    }
}