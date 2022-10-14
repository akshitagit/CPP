// Problem: https://codeforces.com/contest/1742/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include<bits/stdc++.h>
using namespace std ;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long

signed main()
{
	fast;
	{
		int t;
		cin>>t;
		while(t--){
			vector<string>v;
			for(int i=0;i<8;i++){
				string q;
				cin>>q;
				v.push_back(q);
			}
			vector<int>a;
			int tr=0;
			int hor=1,r=0,b=0;
			for(int i=0;i<8;i++)
			{
				for(int j=0;j<8;j++)
				{
					if(v[i][j]=='.')
					{
						hor=0;
						break;
					}
					if(v[i][j]=='R')
					{
						r++;
					}
					else if(v[i][j]=='B')
					{
						b++;
					}
					
				}
				a.push_back(r);
				r=0;
			}
			for(int i=0;i<a.size();i++)
			{
				if(a[i]==8)
				{
					tr=1;
					break;
				}
			}
			if(tr==1)
			cout<<"R"<<endl;
			else
			cout<<"B"<<endl;
			
		}
    }
	return 0;
}    
