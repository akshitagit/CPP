// Smallest and Second smallest in Arrray

#include<iostream>
using namespace std;

int smallest(int arr[],int n){
	int i,smin,min;
	min = arr[0];
	smin = arr[0];
	for(i=0;i<n;i++){
		if(min>arr[i]){
			smin = min;
			min = arr[i];
		}
		else if(smin>arr[i]){
			smin = arr[i];
		}
	}
	cout<<min<<" "<<smin;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	smallest(arr,n);
}