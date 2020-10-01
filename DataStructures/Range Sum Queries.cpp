#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
 
ll N,Q;
vector<ll>V;
vector<ll>P;
 
void init()
{
    for(ll i = 0;i < N; i++)
        P.pb(0);
}
 
void buildPre()
{
    init();
 
    P[0] = V[0];
 
    for(ll i = 1; i < N; i++)
        P[i] = V[i] + P[i-1];
}
 
ll RangeSum(ll L,ll R)
{
    if(L == 0)
        return P[R];
    
    return (P[R] - P[L-1]);
}
 
void solve()
{
    cin>>N>>Q;
 
    for(ll i = 0; i < N; i++)
    {
        ll inp;
        cin>>inp;
        V.pb(inp);
    }
 
    buildPre();
 
    while(Q--)
    {
        ll L,R;
        cin>>L>>R;
        L--;
        R--;
 
        //cout<<L<<" "<<R<<" ";
        
        cout<<RangeSum(L,R)<<endl;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
 
    return 0;
}