// Subarray product  less than K

#include<iostream>
using namespace std;

int subarrayproductlessthank(int arr[],int n,int k){
	int count = 0;
	int i,z;
	for(i=0;i<n;i++){
		if(arr[i] < k){
			count++;
			z = arr[i];
		}
		for(int j=i+1;j<n;j++){
			z = z*arr[j];
			if(z < k)
				count++;
			else
				break;
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

	subarrayproductlessthank(arr,n,k);

}