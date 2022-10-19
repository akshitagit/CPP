#include<bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void wavesort(int arr[], int n){
    for(int i=1; i<n; i+=2){
        if(i>0 && arr[i-1]>arr[i]){
            swap(arr, i, i-1);
        }
        if(i < n-1 && arr[i] < arr[i+1]){
            swap(arr, i, i+1);
        }
    }
}
int main(){
    int n;
    cout<<"Enter number of elements: \n";
    cin>>n;
    
    cout<<"Enter all the elements: \n";
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    wavesort(arr, n);
    for (int i=0; i<n; i++)
       cout << arr[i] << " ";
    return 0;
    
    
}
