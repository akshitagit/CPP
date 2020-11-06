/*  
Given a positive integer n, find the least number of perfect 
square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

Input: n = 12
Output: 3 
Explanation: 12 = 4 + 4 + 4.

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

#include<bits/stdc++.h>

using namespace std;

int numSquares(int n) {
    if(n==0) {
        return 0;
    }

    vector<int> square;
    for(int i=1; i*i<=n; i++) {
        square.push_back(i*i);
    }

    int sq=square.size();

    vector< vector<int> > dp(sq,vector<int>(n+1,0));

    for(int j=1; j<n+1; j++) {
        dp[0][j]=j;
    }

    for(int i=1; i<sq; i++) {
        for(int j=1; j<n+1; j++) {
            if(square[i]>j) {
                dp[i][j]=dp[i-1][j];
            }
            else {
                dp[i][j]=min(dp[i-1][j],dp[i][j-square[i]]+1);
            }
        }
    }

    return dp[sq-1][n];
}

int main() {
    
    int n;
    cin >> n;

    //Output
    cout << numSquares(n) << endl;
}
