//C++ program to put all the negative numbers before 
//positive numbers in an array. The order of
//elements is not important here
#include<bits/stdc++.h>
using namespace std;

//function to rearrange the array- negative no's 
//at first, followed by positive no's.
//QuickSort partition process is applied here
void rearrange(int arr[],int n){
    int j=0;
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            if(i!=j)
                swap(arr[i],arr[j]);
            j++;
        }
    }
}

//function to print the array
void printArray(int arr[], int n){
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
}

//driver code
int main(){
    int arr[]={-1,-2,-3,4,5,6,-7,8,9};
    int n=sizeof(arr)/sizeof(arr[0]);
    rearrange(arr,n);
    printArray(arr,n);
    return 0;
} 