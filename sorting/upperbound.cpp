#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        int y;
        cin>>y;
        for(int x=0;x<n;x++)
        {
            cin>>arr[x];
        }
         
         int left=0;
         int right = n-1;
        int ans = -1;
         while(left<right)
         {
             int m  = left + (right-left)/2;
             if(arr[m]>y)
             {
             
                 ans = arr[m];
                 right = m-1;
             
             }
             else
             {
                 left = m+1;
             }
             
             
         }
          cout<<ans<<" \n";
    }
}