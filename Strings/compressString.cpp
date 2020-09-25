#include<bits/stdc++.h>
using namespace std;

string compressString(string s)
{
	string ans=""; // answer string initialised to null string;
	ans=ans+s[0]; //adding first character
	int count=1; // count to keep track of the of no of repeatitions
	for(int i=1;i<s.size();i++)
	{
		if(ans[(ans.size())-1]==s[i]) count+=1; // if the character encountered is same a prev char. counter is increased
		else {                     // when another character is reached 
			char c = '0';          
			c=c+count;
			ans = ans + c;        // adding the amount of counter as a char into the answer string
 			count=1;              // restoring value of counter to 1
			ans = ans + s[i];     // adding the new character to the answer string
 		}
	}
	// adding the counter value for last character being repeated as the above loop exits without-
	// appending the counter value for the last character into the character string
    char c = '0';
	c=c+count;
	ans = ans + c;
	return ans; // return answer string
}

int main()
{
	string s;
	cout<<"Enter string: "; /// taking input 
	cin>>s;
	cout<<endl;
	string ans= compressString(s); // passing the inout string as an argument into the function 
	cout<<ans;  /// printing answer
}