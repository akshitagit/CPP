#include<bits/stdc++.h>
using namespace std;
int t[100][100];

// Longest Repeating Subsequence

int LCS_topdown(string x, string y, int n, int m) {

	for (int i = 0; i <= n; i++) t[i][0] = 0;
	for (int i = 0; i <= m; i++) t[0][i] = 0;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (x[i - 1] == y[j - 1] && i != j) {
				t[i][j] = 1 + t[i - 1][j - 1];
			}
			else {
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
			}
		}
	}
	return t[n][m];
	// return;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string x = "aabebcdd";
	string y = x;

	int n = x.length();
	int m = y.length();
	cout << LCS_topdown(x, y, n, m); // to create dp table
}
