/*
CountingSort: 
by Divyanshu
@ 2020
*/

#include <algorithm> 
#include <iostream> 
#include <vector> 
using namespace std; 
  
void countSort(vector<int>& arr) 
{ 
    int max = *max_element(arr.begin(), arr.end()); 
    int min = *min_element(arr.begin(), arr.end()); 
    int range = max - min + 1; 
  
    vector<int> count(range), output(arr.size()); 
    for (int i = 0; i < arr.size(); i++) 
        count[arr[i] - min]++; 
  
    for (int i = 1; i < count.size(); i++) 
        count[i] += count[i - 1]; 
  
    for (int i = arr.size() - 1; i >= 0; i--) { 
        output[count[arr[i] - min] - 1] = arr[i]; 
        count[arr[i] - min]--; 
    } 
  
    for (int i = 0; i < arr.size(); i++) 
        arr[i] = output[i]; 
} 
  
void printArray(vector<int>& arr) 
{ 
    for (int i = 0; i < arr.size(); i++) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 
  
int main() 
{ 
    
    
    vector<int> arr; 
    for (int i = 1; i <= 9; i++) {
        int n;
        cin >> n;
        arr.push_back(n);2    
    }
    countSort(arr); 
    printArray(arr); 
    return 0; 
} 


/*
Input:
125 0 695 3 -256 -5 214 44 55 
Output:
-256 -5 0 3 44 55 125 214 695