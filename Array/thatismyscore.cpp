#include <iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main() {
    int t;
    cin>>t;
	while(t-->0){
	    int n;
	    cin>>n;
	    int a[n],b[n],sum=0;
	    for(int i=0;i<n;i++){
	        cin>>a[i]>>b[i];
	    }
	    
	    for(int i=0;i<n-1;i++){
	        for(int j=i+1;j<n;j++){
	            if(a[i] == a[j]){
	                if(b[i]>b[j]){
	                    b[j] = 0;
	                }
	                else{
	                    b[i] = 0;
	                }
	            }
	        }
	    }
	    
	    for(int i=0;i<n;i++){
	        if(a[i]<=8){
	            sum = sum+b[i];
	        }
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
