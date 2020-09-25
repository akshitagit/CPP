/*
Shell Sort
*/

#include<iostream> 
using namespace std;
void sort(int a[],int n)
{
	int gap,i,j,temp;
	for(gap=n/2;gap>0;gap/=2)
	{
		for(i=gap;i<n;i+=1)
		{
			temp=a[i];
			for(j=i;j>=gap&&a[j-gap]>temp;j-=gap)
				a[j]=a[j-gap];
			
			a[j]=temp;
		}
    }
}
 
int main()
{
	int a[20],i,n;
	cout<<"Enter number of elements:";
	cin>>n;
	cout<<"Enter array elements:\n";
	for(i=0;i<n;++i)
		cin>>a[i];
	sort(a,n);
	cout<<"\nArray after shell sort:\n";
	for(i=0;i<n;++i)
		cout<<a[i]<<" ";
    return 0;
}
