// // // Best Time to Buy and Sell Stock

#include<iostream>
using namespace std;

void profit(int arr[],int n){
	int p = 0;
	int b = arr[0];
	int s = arr[0];
	for(int i=0;i<n;i++){
		if(arr[i]<b){
			b = arr[i];
			s = arr[i+1];

		if(s-b>p){
			p = (s-b);
		}
		}
		else if(arr[i]>s){
			s = arr[i];

		if(s-b>0){
			p = (s-b);
			}		
		}
	}
	cout<<p;
}


int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	profit(arr,n);
}
