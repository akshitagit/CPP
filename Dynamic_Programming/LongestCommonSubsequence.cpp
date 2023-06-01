#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

// Given two strings text1 and text2, return the length of their longest common subsequence.
//  If there is no common subsequence, return 0.

// A subsequence of a string is a new string generated from the original string with some 
// characters (can be none) deleted without changing the relative order of the remaining 
// characters.

// For example, "ace" is a subsequence of "abcde".
// A common subsequence of two strings is a subsequence that is common to both strings.


// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.

// Example 2:

// Input: text1 = "abc", text2 = "abc"
// Output: 3
// Explanation: The longest common subsequence is "abc" and its length is 3.

// Approach 1 Top Down
// Time complexity 0(N^2) and space complexity 0(n+m) + 0(N): Stack space
int LCS1(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    // if there is no characters in s1 or s2 return 0
    if (i < 0 || j < 0)
        return 0;
    // applying dp
    if (dp[i][j] != -1)
        return dp[i][j];
    // if there is a match it is a subsequence
    if (s1[i] == s2[j])
    {
        return dp[i][j] = 1 + LCS1(i - 1, j - 1, s1, s2, dp);
    }
    // else find two paths both for s1 and s2
    return dp[i][j] = max(LCS1(i, j - 1, s1, s2, dp), LCS1(i - 1, j, s1, s2, dp));
}

// Approach 2 Bottom Up
// Time Complexity 0(n^2) space: 0(n+m)
int LCS2(string &s1, string &s2)
{

    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> dp(m+1, vector<int>(n+1.0));
    int ans = 0;
     for (int i = 1; i <= m; i++)
     {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] =1+ dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
            ans = max(ans,dp[i][j]);
        }
     }
    return ans;
}

// Approach 3
// Time Complexity 0(n^2) Space:0(n) + 0(m)
int LCS3(string &s1,string&s2)
{
    int n = s1.length();
    int m = s2.length();
    int ans = 0;
    vector<int> prev(n + 1, 0), curr(n + 1);
   
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                curr[j] = 1 + prev[j-1];
            }
            else
            {
                curr[j] = max(curr[j-1],prev[j]);
            }
            ans = max(ans,curr[j]);
        }
        prev = curr;
    }

    return ans;
}


int main()
{

    string text1 = "abcde", text2 = "ace" ;
    // Call any of the functions here
    cout<<"The Ans will be:"<<LCS3(text1,text2)<<endl;

    return 0;
}