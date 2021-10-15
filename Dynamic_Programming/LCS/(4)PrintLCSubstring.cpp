#include<bits/stdc++.h>
using namespace std;
int t[100][100];

// Print Longest Common Substring

void LCS_topdown(string x, string y, int n, int m) {

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
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string x = "acbde";
	string y = "agbde";
	int n = x.length();
	int m = y.length();
	LCS_topdown(x, y, n, m); // to create dp table


	int s = 0, e = 0;
	int ans = INT_MIN;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) { // get the indexes with max element
			if (t[i][j] > ans ) {
				ans = t[i][j];
				s = i;
				e = j;
			}
		}
	}

	cout << s << " " << e << endl;

	string str = "";

	while (t[s][e] != 0) {
		str += x[s - 1];
		s--;
		e--;
	}
	reverse(str.begin(), str.end());
	cout << str; // there can be many LCSubstrings of max length but we are printing one

}
