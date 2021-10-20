#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int>vt;
typedef pair<int,int>pr;
#define fo(i,a,b) for(int i=a; i<=b; i++)
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    ll k;
    for(k=1;k<=t;k++)
    {
        ll n,i,d,c,m;
        string a;
        cin>>n>>d>>c>>m;
        cin>>a;
        ll s[n];
        ll x=0,y=0;
        for(i=0;i<n;i++)
        {
            s[i]=a[i]-'A';
            if(s[i]==3)
            {
                y++;
            }
            else
            {
                x++;
            }
        }
        for(i=0;i<n;i++)
        {
            if(s[i]==3)
            {
                if(d==0)
                break;
                d--;
                y--;
                c+=m;
            }
            else
            {
                if(c==0)
                break;
                c--;
                x--;
            }
        }
        if(i<n && y>0)
        {
            cout<<"Case #"<<k<<": "<<"NO";
        }
        else
        {
            cout<<"Case #"<<k<<": "<<"YES";
        }
    cout<<endl;
    }
}
