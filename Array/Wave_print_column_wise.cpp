#include<bits/stdc++.h>

using namespace std;

int main()
{
     int n,m;
     cin>>m>>n;

     int a[m][n],i,j;

     for(i=0;i<m;i++)
     {
          for(j=0;j<n;j++)
               cin>>a[i][j];
     }
     for(j=0;j<n;j++)
     {
          if(j%2==0)
          {
               for(i=0;i<m;i++)
                    cout<<a[i][j]<<", ";
          }
          else
          {
               for(i=m-1;i>=0;i--)
                    cout<<a[i][j]<<", ";
          }
     }
     cout<<"END";
}
