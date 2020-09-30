// Kadane's Algorithm
// It is use to find maximum subarray sum
#include<bits/stdc++.h>
using namespace std;

void kadaneAlgo(int a[],int n)
{
	int global_max=INT_MIN;
	int curr_max=0;
	for(int i=0;i<n;i++)
	{
		curr_max=curr_max+a[i];
		if(global_max < curr_max)
		{
			global_max=curr_max;
		}
		else if(curr_max < 0)
		{
			curr_max=0;
		}
	} 
	cout<<"Maximum sum of subarray "<<curr_max;
}

int main()
{
	int n=5;
	int a[5]={2,-4,-3,6,7}; // answer is 13
	kadaneAlgo(a,n);
	return 0;
}
