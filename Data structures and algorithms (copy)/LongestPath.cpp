#include<bits/stdc++.h>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define fastio  ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 100

vector<ll> adj[MAX];
map<ll, ll> dp;

ll max1(ll a, ll b)
{
    return (a>b?a:b);
}
void dfs(ll v, ll pv, ll n)
{
    
    dp[v]=v;
    ll mx=0;
    for(auto V:adj[v])
    {
        if(V==pv) continue;
        dfs(V,v,n);
        mx=max(mx,dp[V]);
    }
    dp[v]+=mx;
    
    //return dp[1];
}
int main()
{
    fastio;
    ll N,edge;
    cin>>N>>edge;
    
    
    for(ll i=0; i<edge; i++)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(2,3,N);
    cout<<dp[2]<<"\n";
    
    
    return 0;
}

