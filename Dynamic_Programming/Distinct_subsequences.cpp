/*
Requirements: Find the number of distinct subsequences
                of s which is equal to t.
Logic: We can solve the above problem by applying the concept
        of "Longest Common Subsequence".
*/

//Step 1: Start checking from the end of both the strings.
//step 2: if both the char are matching then
//step 2(a): You have two choices,
//          (i) check next char of s with next char of t, eg. (s[x-1] and t[y-1]) or
//          (ii) check next char of s with same char of t, eg. (s[x-1] and t[y]).
//Step 3: if last char of strings are not matching reduce s by 1, eg. (s[x-1] and t[y])
//**Make sure that you are storing all the sub-problem answers in a table.
//Step 4: return the answer.

//follow the test cases for better understanding.




#include<bits/stdc++.h>
using namespace std;

int findDistinct_subsequence(string s, string t){
    int x = s.length();
    int y = t.length();

    vector<vector<int>> dp(x+1, vector<int>(y+1));

    for(int i=0; i<=x; i++) dp[i][0] = 1;

    for(int i=1; i<=x; i++){
        for(int j=1; j<=y; j++){
            if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[x][y];
}

int main(){
    string s,t;cin>>s>>t;

    int total_distinct_subsequence = findDistinct_subsequence(s,t);

    cout<<total_distinct_subsequence;

}


/*
Test Cases: s = "pqqql", t="ql"

answers: there are three 'q' in s
         use each 'q' with 'l' one by one ('ql', 'ql', 'ql')
         so, there three ways to find t from s.

Output: 3          
*/