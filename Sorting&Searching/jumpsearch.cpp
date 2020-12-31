#include <bits/stdc++.h> 
using namespace std; 
  
int jumpSearch(int arr[], int x, int n) 
{ 
    int step = sqrt(n); 
  
  
    int prev = 0; 
    while (arr[min(step, n)-1] < x) 
    { 
        prev = step; 
        step += sqrt(n); 
        if (prev >= n) 
            return -1; 
    } 
   
    while (arr[prev] < x) 
    { 
        prev++; 
  
        // If we reached next block or end of 
        // array, element is not present. 
        if (prev == min(step, n)) 
            return -1; 
    } 
  
    if (arr[prev] == x) 
        return prev; 
  
    return -1; 
} 
  
 
int main() 
{ 
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 
                34, 55, 89, 144, 233, 377, 610 }; 
    int x = 55; 
    int n = sizeof(arr) / sizeof(arr[0]); 
      
  
    int index = jumpSearch(arr, x, n); 

    cout << "\nNumber " << x << " is at index " << index; 
    return 0; 
} 