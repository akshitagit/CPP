#include <algorithm> 
#include <iostream> 
using namespace std; 
  
int main() 
{ 
    int n;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
      cin>>arr[i];
  
    cout << "Array: "; 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
  
    reverse(arr, arr + n); 
  
    cout << "\nReversed Array: "; 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    return 0; 
} 
