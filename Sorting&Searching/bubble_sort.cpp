#include <iostream>
using namespace std;
void bubblesort_recursive(int *a,int j,int n)
{
    if(n==1)
    {
        return;
    }
    if(j==n-1)
    {
        return bubblesort_recursive(a,0,n-1);
    }
    if(a[j]>a[j+1])
    {
        swap(a[j],a[j+1]);
    }
    bubblesort_recursive(a,j+1,n);
    return;
}
int main(int argc, char **argv)
{
	
    int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bubblesort_recursive(arr,0,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
	return 0;
}
