#include<iostream>
using namespace std;
int left_max(int arr[],int i)
{
    int j;
    int max=arr[0];
    for(j=1;j<i;j++)
    {
        if(arr[j]>max)
           max=arr[j];
    }
    return max;
}
int right_max(int arr[],int n,int i)
{
    int j;
    int max=arr[i+1];
    for(j=i+2;j<n;j++)
    {
        if(arr[j]>max)
        {
           max=arr[j];
        }
    }
    return max;
}
int min(int a,int b)
{
    if(b<a)
        return b;
    else
        return a;
}
int water_trapped(int arr[],int n)
{   int sum=0,result,i;
    for(i=1;i<n-1;i++)
    {
     result=min(left_max(arr,i),right_max(arr,n,i))-arr[i];
     if(result>0)
        sum=sum+result;
    }
    return sum;
}
int main()
{
    int n,i;
    cout<<"Enter the size \n";
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
   cout<<"\n The water trapped is = "<<water_trapped(arr,n);
   return 0;
}
