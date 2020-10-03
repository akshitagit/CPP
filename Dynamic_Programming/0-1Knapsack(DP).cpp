#include<iostream>
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
	    int w;
	    cin>>w;
	    int p[n+1];
	    p[0] = 0;
	    int wt[n+1];
	    wt[0] = 0;
	    for(int i=1;i<n+1;i++)
	    {
	        cin>>p[i];
	    }
	    for(int i=1;i<n+1;i++)
	    {
	        cin>>wt[i];
	    }
	    /*for(int i=1;i<n+1;i++)
	    cout<<p[i]<<" ";
	    cout<<endl;
	    for(int i=1;i<n+1;i++)
	    cout<<wt[i]<<" ";*/
	    int m[n+1][w+1];
	    for(int i=0;i<n+1;i++)
	    {
	        for(int j=0;j<w+1;j++)
	        {
	            if(i==0 || j==0)
	            {
	                m[i][j]=0;
	            }
	            else if(wt[i]<=j)
	            {
	                m[i][j] = max(p[i] + m[i-1][j-wt[i]] , m[i-1][j]);
	            }
	            else
	            {
	                m[i][j] = m[i-1][j];
	            }
	        }
	    }
	    /*for(int i=0;i<n+1;i++)
	    {
	        for(int j=0;j<w+1;j++)
	        cout<<m[i][j];
	        cout<<endl;
	    }*/
	    cout<<m[n][w]<<endl;
	}
	return 0;
}