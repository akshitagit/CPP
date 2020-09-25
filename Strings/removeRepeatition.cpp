#include<bits/stdc++.h>
using namespace std;

string removeRepeatition(s);
{
	string ans = "";
	ans = ans+s[0];
	for(int i=i;i<s.size();i++)
	{
		if(ans[(ans.size())-1]==s[i]);
		else ans = ans + s[i];
	}
	return ans;
}

int main()
{
	string s;
	cin>>s;
	string a= removeRepeatition(s);
	cout<<s;
}