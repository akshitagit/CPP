// Two Sum

#include<iostream>
using namespace std;

int twosum(int arr[],int n,int target){
    for(int i=0;i<n;i++){
        if(arr[i]+arr[i+1] == target){
            cout<<'['<<i<<','<<i+1<<']';
            break;
        }
    }
}

int main(){
    int n,target;
    cin>>n>>target;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    twosum(arr,n,target);
}