#include<bits/stdc++.h>
using namespace std;

void getParenthesis(int l,int r,string v,vector<string> &ds)
{
	
	if(l==0&&r==0)
	{
		ds.push_back(v);
		return ;
	}
	
	if(l==r)
	{
		v.push_back('(');
		getParenthesis(l-1,r,v,ds);
	}
	else if(l<r)
	{
		if(l>0)
		{
			v.push_back('(');
			getParenthesis(l-1,r,v,ds);
			v.pop_back();
		
		}
		v.push_back(')');
		getParenthesis(l,r-1,v,ds);
		
		
	}
	
	return ;
}

int main()
{
	vector<string> ds;
	string v;
	getParenthesis(3,3,v,ds);
	for(auto it:ds)
	{
		cout<<it<<endl;
	}
	
}