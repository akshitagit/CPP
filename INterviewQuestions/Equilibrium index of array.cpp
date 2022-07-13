//Equilibrium index of an array
//Important interview question on array
 
/*
Input: A[] = {-7, 1, 5, 2, -4, 3, 0}
Output: 3
3 is an equilibrium index, because:
A[0] + A[1] + A[2] = A[4] + A[5] + A[6]
*/
#include<bits/stdc++.h>
using namespace std;

void findEquilibrium(int a[],int n)
{
	int sum=0;
	int leftSum=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
	}
	for(int i=0;i<n;i++)
	{
		sum=sum-a[i];
		if(sum==leftSum)
		{
			cout<<i;
			return;
		}
		leftSum+=a[i];
	}
	cout<<"-1";
}

int main()
{
	int a[]={-7, 1, 5, 2, -4, 3, 0};
	int n=7;
	findEquilibrium(a,n);
	return 0;
}
