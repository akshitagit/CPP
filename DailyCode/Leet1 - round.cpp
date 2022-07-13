// incomplete

#include<iostream>
using namespace std;

int round(int arr[],int n){
	int brr[] = {'G','L','R'};
	int pos = 0;
	int left = 0;
	int right = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(brr[i] == arr[j]){
				pos++;
				if(brr[i+1] == arr[j+1]){
					left--;
				}
			}
		}
	}	

}

int main(){
	int n;
	int arr[n];
	n = sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	round(arr);
}