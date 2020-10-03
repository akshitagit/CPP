/*Longest increasing subsequence is the maximum length of the non contiguous numbers in an array
  such that when taken these numbers(in order) they are always in a sorted manner.
  The idea is to take two loops for i and j and take i from 1 index and j from 0 
  The rest of the concept can be understood from the given algorithm.
*/ 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    if(n==1)
	    cout<<1<<endl;
	    else
	    {
    	    int arr[n];
    	    
    	    int result[n];
    	    for(int i=0;i<n;i++)
    	    result[i] = 1;
    	    for(int i=0;i<n;i++)
    	    {
    	        cin>>arr[i];
    	    }
    	    int max = INT_MIN;
    	    for(int i=1;i<n;i++)
    	    {
    	        for(int j=0;j<i;j++)
    	        {
    	            if(arr[j]<arr[i])
    	            {
    	                result[i] = std::max(result[i],result[j]+1);
    	            }
    	        }
    	    }
    	    /*for(int i=0;i<n;i++)
    	    cout<<result[i]<<" ";
    	    cout<<endl;*/
    	    for(int i=0;i<n;i++)
    	    {
    	        if(max<result[i])
    	            max = result[i];
    	    }
    	    cout<<max<<endl;
	    }
	}
	return 0;
}



