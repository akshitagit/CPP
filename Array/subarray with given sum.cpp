#include<iostream>
using namespace std;
int main()
{
    int n,s,i,start,flag=0;
    cin>>n>>s;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    start=0;
    int sum=0;
    for(i=0;i<=n;i++)
    {
       while(sum>s && start<i-1)
        {
            sum=sum-arr[start];
            start++;
        }
        if(sum==s)
        {
            cout<<"\n The position of sub-array is from  "<<start+1<<"  to  "<<i;
            flag=1;
            break;
        }
        if(i<n)
        sum=sum+arr[i];
    }
    if(flag==0)
    {
        cout<<"Not found";
    }
    return 0;
}
