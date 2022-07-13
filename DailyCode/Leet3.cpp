#include<iostream>
using namespace std;

int print_max(int arr[],int n){
	int count = 0;
	int t = n/3;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]==arr[j]){
				count++;
			}
		}
		if(count >= t){
			cout<<arr[i]<<" ";
		}
		count = 0;
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	print_max(arr,n);
}
