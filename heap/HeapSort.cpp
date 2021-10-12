#include <bits/stdc++.h>
using namespace std;

// To heapify a subtree rooted with node i which is
// Heapify:- A process which helps regaining heap properties in tree after removal 
void heapify(int A[], int n, int i)
{
   int largest = i; // Initialize largest as root
   int left_child = 2 * i + 1; // left = 2*i + 1
   int right_child = 2 * i + 2; // right = 2*i + 2

   // If left child is larger than root
   if (left_child < n && A[left_child] > A[largest])
       largest = left_child;

   // If right child is larger than largest so far
   if (right_child < n && A[right_child] > A[largest])
       largest = right_child;

   // If largest is not root
   if (largest != i) {
       swap(A[i], A[largest]);

       // Recursively heapify the affected sub-tree
       heapify(A, n, largest);
   }
}

// main function to do heap sort
void heap_sort(int A[], int n)
{
   // Build heap (rearrange array)
   for (int i = n / 2 - 1; i >= 0; i--)
       heapify(A, n, i);

   // One by one extract an element from heap
   for (int i = n - 1; i >= 0; i--) {
       // Move current root to end
       swap(A[0], A[i]);

       // call max heapify on the reduced heap
       heapify(A, i, 0);
   }
}

/* A  function to print sorted Array */
void printArray(int A[], int n)
{
   for (int i = 0; i < n; ++i)
       cout << A[i] << " ";
   cout << "\n";
}

// Driver program
int main()
{
   int A[] = { 22, 19, 3, 25, 26, 7 }; // array to be sorted
   int n = sizeof(A) / sizeof(A[0]); // n is size of array

   heap_sort(A, n);

   cout << "Sorted array is \n";
   printArray(A, n);
}