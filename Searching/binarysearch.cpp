#include<iostream>
using namespace std;

int bsearch(int arr[], int left, int right, int x)
{
	while(left<=right){
		int mid=(right+left)/2;
		if(arr[mid]==x)
		{
			return mid;
		}
		else if(arr[mid]>x)
		{
			right=mid-1;
			
		}
		else
		{
			left=mid+1;
			
		}
	}
}

int main()
{
	int num,myarr[10],output,i,j,temp;
	cout<<"Enter the 10 integers : "<<endl;
	for(int i=0;i<10;i++)
	{
		cin>>myarr[i];
	}
	for (i=0;i<10;i++)
	{
		for(j=i;j<10;j++)
		{
			if (myarr[i]>myarr[j])
			{
				temp=myarr[i];
				myarr[i]=myarr[j];
				myarr[j]=temp;
			}
		}
	}
	cout<<"The sorted array is : "<<endl;
	for (i=0;i<10;i++)
	{
		cout<<myarr[i]<<" ";
	}
	cout<<endl;
	cout<<"Enter the number that you want to search in the array : "<<endl;
	cin>>num;
	output=bsearch(myarr, 0,9,num);
	if(output==-1)
	{
		cout<<"Not found !"<<endl;
	}
	else
	{
		cout<<"Element found at position : "<<output<<endl;
	}
	return 0;
}
