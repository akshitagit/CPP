#include <iostream>
#include<climits>
using namespace std;
bool ispossible(int arr[],int n,int m,int cur_min)
{
    int stu=1;
    int pagesred=0;
    for(int i=0;i<n;i++)
    {
        if(pagesred+arr[i]>cur_min)
        {
            stu++;pagesred=arr[i];
            if(stu>m)
            {
                return false;
            }
        }
        else{
            pagesred+=arr[i];
        }
    }
    return true;
    
}
int findpages(int arr[],int n,int m)
{
    int sum=0;
    if(n<m)
    {
        return -1;
    }
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    int s=arr[n-1];
    int e=sum;
    int ans=INT_MAX;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(ispossible(arr,n,m,mid))
        {
            ans=min(ans,mid);
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}
int main()
{
	int t;
    cin>>t;
    int n,m;
    for(int i=0;i<t;i++)
    {
        int n,m;
        cin>>n>>m;
        int arr[1000];
        for(int j=0;j<n;j++)
        {
            cin>>arr[j];
        }
        cout<<findpages(arr,n,m)<<endl;
    }
	return 0;
}
