#include<bits/stdc++.h>
using namespace std;
int t[100][100];

// Print Shortest Common Supersequence

void LCS_topdown(string x, string y, int n, int m) {

	for (int i = 0; i <= n; i++) t[i][0] = 0;
	for (int i = 0; i <= m; i++) t[0][i] = 0;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {

			if (x[i - 1] == y[j - 1]) {
				t[i][j] = 1 + t[i - 1][j - 1];
			}
			else {
				t[i][j] = max(t[i - 1][j], t[i][j - 1]);
			}
		}
	}
	// return t[n][m];
	return;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string x = "aggtab";
	string y = "gxtxayb";

	int n = x.length();
	int m = y.length();
	LCS_topdown(x, y, n, m); // to create dp table

	int i = n, j = m;
	string s = "";

	while (i > 0 && j > 0) {

		if (x[i - 1] == y[j - 1]) {
			s += x[i - 1];
			i--;
			j--;
		}
		else {
			if (t[i - 1][j] > t[i][j - 1]) {
				s += x[i - 1];
				i--;
			}
			else {
				s += y[j - 1];
				j--;
			}
		}
	}

	while (i > 0) {
		s += x[i - 1];
		i--;
	}
	while (j > 0) {
		s += y[j - 1];
		j--;
	}

	reverse(s.begin(), s.end());
	cout << s << endl;


}
