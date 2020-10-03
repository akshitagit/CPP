/*The idea is if the character is same then print the diagonal element
in that dp matrix else find the minimum of previous columm,row and diagonal
element and set minimum at the current position in dp matirx and at last
print the last row and column value as it will give us the minimum*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int minimum(int a,int b,int c)
{
    int result = min(min(a,b),c);
    return result;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int p,q;
	    cin>>p>>q;
	    char s1[p];
	    char s2[q];
	    cin>>s1>>s2;
	    //cout<<s1<<" "<<s2;
	    int dp[p+1][q+1];
	    for(int i=0;i<p+1;i++)
	    {
	        for(int j=0;j<q+1;j++)
	        {
	            
	            if(i == 0)
	            dp[i][j] = j;
	            
	            else if(j == 0)
	            dp[i][j] = i;
	            
	            else if(s1[i-1] == s2[j-1])
	            dp[i][j] = dp[i-1][j-1];
	            
	            else
	            {
	                dp[i][j] = 1 + minimum(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]);
	            }
	            
	        }
	    }
	    cout<<dp[p][q]<<endl;
	}
	return 0;
}