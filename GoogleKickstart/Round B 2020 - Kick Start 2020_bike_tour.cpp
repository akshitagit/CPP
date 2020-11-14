#include<bits/stdc++.h>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDJE
		freopen("input.txt", "r+",stdin);
		freopen("output.txt", "w+",stdout);
	#endif
		int t,i,j,k,n,z=0;
		cin>>t;
		for(i=0;i<t;i++)
		{

			cin>>n;
			int *a = new int[n];
			for(k=0;k<n;k++)
			{
				cin>>a[k];
			}
			for(j=0;j<n;j++)
			{
				if(j==0)
				{
				    continue;
				}
				if(j==n-1)
				{
				    break;
				}
				else
				{
					if(a[j]>a[j+1] && a[j]>a[j-1])
					{
					    z++;
						
					}
				}
			}
			cout<<"Case #"<<i+1<<": "<<z<<"\n";
			z=0;
		}
		return 0;
}