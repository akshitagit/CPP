// K-diff Pairs in an Array

#include<iostream>
using namespace std;

int diffPairs(int arr[],int n,int k){
	int count = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]-arr[j] == k || arr[j]-arr[i] == k){
				count++;
			}		
		}
	}
	cout<<count;
}

int main(){
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	diffPairs(arr,n,k);
}