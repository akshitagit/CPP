#include<bits/stdc++.h>
using namespace std;
int t[100][100];

// Palindrome Partitioning - Min number of partitions
// Partition string such that each string is a palindrome

// Analogy to minimum palindromes substrings a string has

int dp[100][100];

bool ispalin(string s, int i, int j) {

	while (i <= j) {
		if (s[i] != s[j]) return false;
		i++;
		j--;
	}
	return true;
}

int solve(string s, int i, int j) {

	int ans = INT_MAX;
	if (i >= j) return 0; // s =" " or s="a" is already palindrome

	if (ispalin(s, i, j)) return 0;

	for (int k = i; k <= j - 1; k++) {

		int temp_ans = solve(s, i, k) + solve(s, k + 1 , j) + 1;
		ans = min(temp_ans, ans);

	}

	return ans;
}

int solve_mem(string s, int i, int j) {

	int ans = INT_MAX;
	if (i >= j) return 0; // s =" " or s="a" is already palindrome

	if (ispalin(s, i, j)) return 0;

	int left, right;
	for (int k = i; k <= j - 1; k++) {

		if (dp[i][k] == -1) left = solve_mem(s, i, k);
		else left = dp[i][k];

		if (dp[k + 1][j] == -1) right = solve_mem(s, k + 1, j);
		else left = dp[k + 1][j];

		ans = min(1 + left + right, ans);

	}

	return dp[i][j] = ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s = "nitik";
	memset(dp, -1, sizeof(dp));
	cout << solve(s, 0, s.length() - 1) << endl;
	cout << solve_mem(s, 0, s.length() - 1) << endl;
}
