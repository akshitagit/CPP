/*
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls.
 The stalls are located along a straight line at positions x1,...,xN.
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall.
To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible.
What is the largest minimum distance?
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,c;
        cin>>n>>c;
        long long*a=new long long[n];
        for(int j=0;j<n;j++)
        {
            cin>>a[j];
        }
        sort(a,a+n);
        int start=0,end=a[n-1]-a[0];
        int ans=0;
        while(end>=start)
        {
            int mid=(end+start)/2;
            int cows=1,q=0,correct=0;
            for(int k=1;k<n;k++)
            {
                if(a[k]-a[q]>=mid)
                {
                    cows++;
                    q=k;
                    if(cows==c)
                    {
                        correct=1;
                        break;
                    }
                }
            }
            if(correct==0)
            {
                end=mid-1;
            }
            else
            {
                ans=mid;
                start=mid+1;
            }
        }
        cout<<ans<<endl;
    }

}