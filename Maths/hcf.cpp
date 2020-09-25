#include <bits/stdc++.h> 
using namespace std; 
  
// Function to return gcd of two numbers a and b 
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 
  
// Function to find gcd of array
int findGCD(vector<int> arr, int n) 
{ 
    int result = arr[0]; 
    for (int i = 1; i < n; i++) 
    { 
        result = gcd(arr[i], result); 
  
        if(result == 1) 
        { 
           return 1; 
        } 
    } 
    return result; 
} 


int main() 
{ 
    int n;

    //input size
    cin>>n;

    vector<int> arr(n);

    //input array
    for(int i=0;i<n;i++)
        cin>>arr[i];

    //function calling
    cout << findGCD(arr, n); 

    return 0; 
} 