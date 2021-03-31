#include<bits/stdc++.h>
using namespace std;
int main(){
	int n ;
	cin>>n;
	
	int a[1000];
	int maxSum= 0 ;
	int cs = 0;
	
	for(int i = 0 ; i< n ; i++){
		cin>>a[i];
	}
	
	//Kadane's Algorithm for max subarray sum
	for( int i = 0 ; i< n ; i++){
		cs = cs + a[i];
		if (cs< 0 ){
			cs = 0;
		}
	 maxSum= max(cs,maxSum);
	}
	
	
	cout<<"Maximum sum is : "<<maxSum<<"\n";
	
	return 0 ;
	
}
