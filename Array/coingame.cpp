#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void piles(int arr[],int n){
    long long int even = 0;
    long long int odd = 0;
    for(int i=0;i<n;i++){
        if((i)%2==0){
            even = even + arr[i];
        }
        else{
            odd = odd + arr[i];
        }
    }
    
    int ans = (even>odd)?odd:even;
    cout<<2*ans;
}

int main(void) {
	long long int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
	    cin>>arr[i];
	}
	piles(arr,n);
	return 0;
}

