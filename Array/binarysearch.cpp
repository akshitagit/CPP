#include <bits/stdc++.h> 
using namespace std; 
  
// A recursive binary search function. It returns 
// location of x in given array arr[l..r] is present, 
// otherwise -1 
int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        if (arr[mid] == x) 
            return mid; 
  
       else if (arr[mid] > x) //now this condition will not be evaluated if earlier is true
            return binarySearch(arr, l, mid - 1, x); 
       else
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    return -1; 
} 
  
int main(void) 
{ 
    int arr[] = { 2, 3, 4, 10, 40 }; 
    int x = 10; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int result = binarySearch(arr, 0, n - 1, x); 
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result; 
    return 0; 
} 
