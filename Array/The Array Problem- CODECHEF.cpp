/* ARRPROB */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
signed main()
{
    fast
    int t; cin>>t;
    while(t--)
    {
     int n; cin>>n;
     int arr[n];
     int sum=0;
     for(int i=0;i<n;i++)
     {
         cin>>arr[i];
          sum+=arr[i];
     }
          for(int i=0;i<n;i++)
{
    cout<<sum-arr[i]<<" ";
}
cout<<endl;
        
    }

    
    return 0;
}
