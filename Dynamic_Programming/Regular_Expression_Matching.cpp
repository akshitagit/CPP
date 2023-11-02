//Given a string s and a pattern p, implement regular expression matching with support for '.' (matches any single character) and '*' (zero or more of the preceding element).
//Example:

//Input: s = "mississippi", p = "mis*is*p*."
//Output: false

#include <iostream>
#include <vector>

using namespace std;

bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;

    // Fill the first row
    for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    // Fill the dp array using dynamic programming
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s = "mississippi";
    string p = "mis*is*p*.";
    bool result = isMatch(s, p);
    cout << "Matching result: " << (result ? "true" : "false") << endl;
    return 0;
}
