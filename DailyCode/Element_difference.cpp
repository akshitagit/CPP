#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,i,p;
    cin>>n>>k;
    int a[n],x[100000];
    memset(x,0,sizeof(x));
    for(i=0;i<n;i++)
    {
      cin>>a[i];
      x[a[i]]++;
    }
    p=0;
    for(i=0;i<n;i++)
    {
      if(a[i]<k){continue;}
      if(x[a[i]-k]>0){p=1;}
    }
    if(p==1){cout<<"YES\n";}
    else{cout<<"NO\n";}
}
