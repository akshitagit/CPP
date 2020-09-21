/*Radix Sort Algorithm : 

1. Radix Sort is a non-comparative sorting algorithm
2. It avoids comparison by creating and distributing elements into buckets
according to the radix
3. For elements with more than one significant digit, this bucketing process
is repeated for every digit, while preserving the ordering of prior step
untill all digits have been considered. So, Radix Sort is also called bucket
sort or digital sort.
4. Typically Radix sort uses counting sort as a subroutine to sort.
It has linear time complexity which is better than 0(n log n) of comparative sort algos.

Time Complexity : 0(n+k)
Space Complexity : O(n+k)

where n= no. of elements and k = range of inputs
*/

#include<iostream>
using namespace std;

void countingsort(int *arr, int n, int div1)
{
	int output[n];
	int count[10]={0};
	
	for(int i=0;i<n;i++)
	{
		count[(arr[i]/div1)%10]++;
	}
	for(int i=1;i<10;i++)
	{
		count[i]+=count[i-1];
	}
	for(int i=n-1;i>=0;i--)
	{
		output[--count[(arr[i]/div1)%10]]=arr[i];
		//count[(arr[i]/div1)%10]--;
	}
	for(int i=0;i<n;i++)
	{
		arr[i]=output[i];
	}
}

void radixsort(int *arr, int n)
{
	int m=arr[0];
	for(int i=0;i<n;i++)
	{
		m=max(arr[i], m);
	}
	cout<<"Max is : "<<m<<endl;
	for(int div1=1;m/div1>0;div1*=10)
	{
		countingsort(arr, n, div1);
	}
}


int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Before sorting : "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	radixsort(arr, n); //radix sort called here
	
	cout<<"After sorting : "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	
	
}
