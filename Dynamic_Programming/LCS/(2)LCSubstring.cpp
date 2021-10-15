#include<bits/stdc++.h>
using namespace std;
int t[100][100];

// Longest Common Substring

int LCS_topdown(string x, string y, int n, int m) {

	for (int i = 0; i <= n; i++) t[i][0] = 0;
	for (int i = 0; i <= m; i++) t[0][i] = 0;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (x[i - 1] == y[j - 1]) {
				t[i][j] = 1 + t[i - 1][j - 1];
			}
			else {
				t[i][j] = 0;
			}

		}
	}
	int ans = INT_MIN;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			ans = max(ans, t[i][j]);
		}
	}

	return ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string x = "abcde";
	string y = "abce";
	int n = x.length();
	int m = y.length();
	cout << LCS_topdown(x, y, n, m) << endl;
}
