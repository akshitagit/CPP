#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios::sync_with_stdio(0);
    ll t,r;
    cin>>t;
    for(r=1;r<=t;r++)
    {
        ll rs,rh,i;
        cin>>rs>>rh;
        ll n;
        cin>>n;
        ll d=(rs*rs)+(rh*rh)+2*rs*rh;
        if(n==0)
        {
            ll m,f=0,h=0;
        cin>>m;
        ll z[m],w[m];
        for(i=0;i<m;i++)
        cin>>z[i]>>w[i];
        ll e;
        for(i=0;i<m;i++)
        {
            e=z[i]*z[i]+w[i]*w[i];
            if(e<=d)
            h++;
        }
                 cout<<"Case #"<<r<<": "<<f<<" "<<h<<endl;
                 continue;
        }
        ll x[n],y[n];
        for(i=0;i<n;i++)
        {
            cin>>x[i]>>y[i];
        }
        ll m;
        cin>>m;
        ll z[m],w[m];
        for(i=0;i<m;i++)
        cin>>z[i]>>w[i];
        if(m==0)
        {
            ll f=0,h=0;
        ll e;
        for(i=0;i<n;i++)
        {
            e=x[i]*x[i]+y[i]*y[i];
            if(e<=d)
            f++;
        }
                 cout<<"Case #"<<r<<": "<<f<<" "<<h<<endl;
                 continue;
        }
        ll e;
        vector<ll>a(n,1e18);
        vector<ll>b(m,1e18);
        for(i=0;i<n;i++)
        {
            e=x[i]*x[i]+y[i]*y[i];
            if(e<=d)
            a[i]=e;
        }
        for(i=0;i<m;i++)
        {
            e=z[i]*z[i]+w[i]*w[i];
            if(e<=d)
            b[i]=e;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        ll f=0,h=0;
        for(auto x:a)
        {
            if(x<b[0])
            f++;
            else
            break;
        }for(auto x:b)
        {
            if(x<a[0])
            h++;
            else
            break;
        }
          cout<<"Case #"<<r<<": "<<f<<" "<<h;
       cout<<endl;
    }
}
