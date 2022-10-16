#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[] = {15,12,13,18,5,9};
    int n = sizeof(arr)/sizeof(int);
    
    cout<<"The given array is:"<<endl;
    for(int j =0 ; j<n ; j++ ){
        cout<<arr[j]<<' ';
    }
    
    sort(arr, arr + n);  // sorting array
    int answer[10];     // answer array
    
    int begin = 0, end = n-1;  // two pointers
    
    for(int j =0 ; j< n ; j++ ){
        if(j%2 == 0)   //even position
        {
            answer[j] = arr[end];
            end--;
        }
        else {          // odd position
            answer[j] = arr[begin];
            begin++;
        }
    }
    
    cout<<endl<<"The rearranged array is:"<<endl;
    for(int j =0 ; j<n ; j++ ){
        cout<<answer[j]<<' ';
    }
    
  return 0;
}
