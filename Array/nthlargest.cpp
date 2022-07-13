#include <iostream>
#include <bits/stdc++.h> 
using namespace std;

void largest(int arr[],int n,int k){
        int i;
        sort(arr,arr+n,greater<int>());
        
        cout<<arr[i+1];
        }
        
int main(){
    int num,nth;
    int arr[num];
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }
    cin>>nth;
    largest(arr,num,nth);
}
