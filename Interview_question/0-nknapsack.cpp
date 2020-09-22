#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll n,c,i,k=0,j;
    cin>>n>>c;
    vector<ll> v(n),w(n);
    for(i=0;i<n;i++)
    cin>>w[i];
    for(i=0;i<n;i++)
    cin>>v[i];
    vector<ll> dp(c+1);
    dp[0]=0;
    for(i=1;i<=c;i++)
    {
        k=0;
        //cout<<dp[i]<<" ";
        for(j=0;j<n;j++)
        {
            if(w[j]<=i)
            {
                k=max(k,dp[i-w[j]]+v[j]);
            }
            
        }
        dp[i]=k;
        //cout<<dp[i]<<"\n";;
    }
    
   cout<<dp[c];
	return 0;
}
