#include <bits/stdc++.h>
using namespace std;

struct MinHeapNode //min heap node
{
    int element; //element to be stored
    int i;       //index of array from which array is taken
    int j;       //index of next element to be picked from the array
};
void swap(MinHeapNode *x, MinHeapNode *y)
{
    MinHeapNode temp = *x;
    *x = *y;
    *y = temp;
}
class HeapNode
{ //pointer to the array of elements in heap
    MinHeapNode *harr;
    int heap_size;

public:
    // to get index of left child of node at index i
    int left(int i) { return (2 * i + 1); }

    // to get index of right child of node at index i
    int right(int i) { return (2 * i + 2); }

    //constructor creates min heap of the given size
    HeapNode(MinHeapNode a[], int size)
    {
        heap_size = size;
        harr = a; //store address of the array
        int i = (heap_size - 1) / 2;
        while (i >= 0)
        {
            MinHeapify(i);
            i--;
        }
        //for(int i=N/2-1;i>=0;i--) heapify(i);
    }
    void MinHeapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l].element < harr[i].element)
            smallest = l;

        if (r < heap_size && harr[r].element < harr[smallest].element)
            smallest = r;

        if (smallest != i)
        {
            swap(&harr[i], &harr[smallest]);
            MinHeapify(smallest);
        }
    }

    // to get the root
    MinHeapNode getMin() { return harr[0]; }

    void replaceMin(MinHeapNode x)
    {
        harr[0] = x;
        MinHeapify(0);
    }
};
#define n 4
int *mergeKArrays(int arr[][n], int k)
{

    // To store output array
    int *output = new int[n * k];

    // Create a min heap with k heap nodes.
    // Every heap node has first element of an array
    MinHeapNode *harr = new MinHeapNode[k];
    for (int i = 0; i < k; i++)
    {

        // Store the first element
        harr[i].element = arr[i][0];

        // index of array
        harr[i].i = i;

        // Index of next element to be stored from the array
        harr[i].j = 1;
    }

    // Create the heap
    HeapNode hp(harr, k);

    // Now one by one get the minimum element from min
    // heap and replace it with next element of its array
    for (int count = 0; count < n * k; count++)
    {
        // Get the minimum element and store it in output
        MinHeapNode root = hp.getMin();
        output[count] = root.element;

        // Find the next elelement that will replace current
        // root of heap. The next element belongs to same
        // array as the current root.
        if (root.j < n)
        {
            root.element = arr[root.i][root.j];
            root.j += 1;
        }
        // If root was the last element of its array
        // INT_MAX is for infinite
        else
            root.element = INT_MAX;

        // Replace root with next element of array
        hp.replaceMin(root);
    }

    return output;
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main()
{
    // int a, n;
    // cin >> a >> n;
    // int arr[a][n];
    // for (int i = 0; i < a; i++) //array index
    // {
    //     for (int j = 0; j < n; j++) //index in the array
    //     {
    //         cin >> arr[i][j];
    //     }
    // }
    int arr[][n] = {{2, 6, 12, 34},
                    {1, 9, 20, 1000},
                    {23, 34, 90, 2000}};
    int k = sizeof(arr) / sizeof(arr[0]);

    int *output = mergeKArrays(arr, k);
    cout << "Merged Arraya are\n";
    printArray(output, n * k);
    return 0;
}