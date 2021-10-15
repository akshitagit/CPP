#include<bits/stdc++.h>
using namespace std;
int t[100][100];
int dp[100][100];

// Longest Common Subsequence

int LCS(string x, string y, int n, int m) {

	if (n == 0 || m == 0) return 0;

	if (x[n - 1] == y[m - 1]) {
		return 1 + LCS(x, y, n - 1, m - 1);
	}

	else {
		return max(LCS(x, y, n - 1, m) , LCS(x, y, n, m - 1));
	}

}

int LCS_memoize(string x, string y, int n, int m) {

	if (n == 0 || m == 0) return 0;


	if (dp[n][m] == -1) {

		if (x[n - 1] == y[m - 1]) {
			return dp[n][m] = 1 + LCS(x, y, n - 1, m - 1);
		}

		else {
			return dp[n][m] = max(LCS(x, y, n - 1, m) , LCS(x, y, n, m - 1));
		}

	}


	else return dp[n][m];

}

int LCS_topdown(string x, string y, int n, int m) {

	for (int i = 0; i <= n; i++) t[i][0] = 0;
	for (int i = 0; i <= m; i++) t[0][i] = 0;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (x[i - 1] == y[j - 1]) {
				t[i][j] = 1 + t[i - 1][j - 1];
			}

			else {
				t[i][j] = max(t[i - 1][j] , t[i][j - 1]);
			}

		}
	}
	return t[n][m];

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string x = "dcbgfa";
	string y = "gfdcba";
	int n = x.length();
	int m = y.length();
	memset(dp, -1, sizeof(dp));
	cout << LCS(x, y, n, m) << endl;
	cout << LCS_memoize(x, y, n, m) << endl;
	cout << LCS_topdown(x, y, n, m) << endl;
}
