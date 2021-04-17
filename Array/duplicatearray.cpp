#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void duplicate(int arr[],int n){

   sort(arr,arr+n);
    
    int c = arr[0];
    int ct =0;
    for(int i=1;i<n;i++){
        if(arr[i] == c){
            ct++;
        }
        else{
            if(ct>0){
                cout<<c;
            }
            c = arr[i];
            ct = 0;
        }
    }
    if(ct > 0){
        cout<<c;
    }
}

int main(void) {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	duplicate(arr,n);
	return 0;
}
