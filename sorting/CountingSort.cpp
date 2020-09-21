/*Counting Sort is a sorting algorithm that sorts the elements of the array by
counting the number of occurences of each unique element in the array.

The count is stored in an auxillary array and the sorting is done by mapping 
the count as an index of the auxillary array. This mapping is done by performing
arithmetic calculations on those counts to determine the positions of each 
key value (unique element) in the output sequence.

It is often used as a subroutine in another sorting algorithm, radix sort that
can handle larger keys more efficiently.

Counting Sort is not a Comparison Sort

Time Complexity : 0(n+k)
Space Complexity : 0(n+k)
n: number of elements in input array
k: range of input
*/

/* WORKING OF COUNTING SORT

1) Take input array and range(no. of unique integers involved)

2) Create the output array of size same as input array.
Create count array with size equal to the range and initialize with 0

3) Count each element in the input array and place the count at the 
appropriate index of the count array.

4) Modify the count array by adding the (n-1)term to the nth term (Cumulative sum)
The modified count array indicates the position of each element in the output array.

5) Output each object from the input array into the sorted output array and followed 
by decreasing its count by 1.

6) Print the sorted array
*/


#include<iostream>
using namespace std;

void countingsort(int *arr, int s, int r)
{
	int output[s];
	int count[r];
	//initialize all elements to 0
	for(int i=0;i<r;i++)
	{
		count[i]=0;
	}
	//take count of elements of input array in the count array
	for(int i=0;i<s;i++)
	{
		count[arr[i]]++;
	}
	//cumulative sum in count array
	for(int i=1;i<r;i++)
	{
		count[i]+=count[i-1];
	}
	//placing input array elements in proper array positions such that array is sorted
	for(int i=0;i<s;i++)
	{
		output[--count[arr[i]]]=arr[i];
	}
	for(int i=0;i<s;i++)
	{
		arr[i]=output[i];
	}
}

int main()
{
	int size=0;
	int range=10;
	cout<<"Enter the size : ";
	cin>>size;
	int arr[size];
	cout<<"Enter elements of the array: "<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	cout<<endl;
	cout<<"Before sorting: "<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	countingsort(arr, size, range);
	cout<<"After sorting: "<<endl;
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
}

