#include<bits/stdc++.h>
using namespace std;

string removeRepeatition(s);
{
	string ans = ""; // answer string initially empty
	ans = ans+s[0]; // adding the first character to answer string
	for(int i=i;i<s.size();i++)
	{
		if(ans[(ans.size())-1]==s[i]); /////if the present character is same as previous character..skip character
		else ans = ans + s[i]; ////if the present character is different to the previous character add character to answer string 
	}
	return ans; /// returns answer
}

int main()
{
	string s;
	cout<<"Enter string: ";
	cin>>s;
	cout<<endl;
	string a= removeRepeatition(s);
	cout<<s;
}
