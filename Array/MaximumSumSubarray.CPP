#include<iostream> 
using namespace std; 
  
int maxSubArraySum(int a[], int size) 
{ 
   int max_so_far = a[0]; 
   int curr_max = a[0]; 
  
   for (int i = 1; i < size; i++) 
   { 
        curr_max = max(a[i], curr_max+a[i]); 
        max_so_far = max(max_so_far, curr_max); 
   } 
   return max_so_far; 
} 
  
/* Driver program to test maxSubArraySum */
int main() 
{ 
   int n=0,i=0;
   cin>>n;
   int a[n];
   for(i=0;i<n;i++)
   {
      cin>>a[i];
   }
   int max_sum = maxSubArraySum(a, n); 
   cout << "Maximum contiguous sum is " << max_sum; 
   return 0; 
} 
