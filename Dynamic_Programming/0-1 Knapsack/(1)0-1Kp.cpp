#include<bits/stdc++.h>
using namespace std;

// DP is enhanced recursion
// 0-1 Knapsack [each item is single unit]

int dp[100][100]; //global
int t[100][100];


int knapsack(int *val, int *wt, int W, int n) {

	if (n == 0 || W == 0) return 0;

	if (wt[n - 1] <= W) {
		return max(val[n - 1] + knapsack(val, wt, W - wt[n - 1], n - 1) , knapsack(val, wt, W, n - 1));
	}
	else if (wt[n - 1] > W) {
		return knapsack(val, wt, W, n - 1);
	}
}

int knapsack_memoize(int *val, int *wt, int W, int n) {

	if (n == 0 || W == 0) return 0;

	if (dp[n][W] != -1) return dp[n][W];

	else {

		if (wt[n - 1] <= W) {
			return dp[n][W] = max(val[n - 1] + knapsack(val, wt, W - wt[n - 1], n - 1) , knapsack(val, wt, W, n - 1));
		}
		else if (wt[n - 1] > W) {
			return dp[n][W] = knapsack(val, wt, W, n - 1);
		}

	}
}

int knapsack_topdown(int *val, int *wt, int W, int n) {


	for (int i = 0; i <= W; i++) t[0][i] = 0;
	for (int i = 0; i <= n; i++) t[i][0] = 0;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= W; j++) {

			if (wt[i - 1] <= j) {
				t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]] , t[i - 1][j]);
			}
			else {
				t[i][j] = t[i - 1][j];

			}
		}


	}
	return t[n][W];
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int wt[] = {4, 5, 1};
	int val[] = {1, 2, 3};
	int W = 10;
	int n = sizeof(val) / sizeof(int);
	memset(dp, -1, sizeof(dp));
	cout << knapsack(val, wt, W, n) << endl;
	cout << knapsack_memoize(val, wt, W, n) << endl;
	cout << knapsack_topdown(val, wt, W, n) << endl;
}
