#include<bits/stdc++.h>
using namespace std;
int t[100][100];

// Rod Cutting Problem
int Unbknapsack(int *wt, int *val, int W, int n) {

	for (int i = 0; i <= W; i++) t[0][i] = 0;
	for (int i = 0; i <= n; i++) t[i][0] = 0;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= W; j++) {

			if (wt[i - 1] <= j) {
				t[i][j] = max(val[i - 1] + t[i][j - wt[i - 1]] , t[i - 1][j]);
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

	int wt[] = {4, 9, 2, 2};
	int val[] = {1, 2, 5, 4};
	int W = 10;
	int n = sizeof(val) / sizeof(int);
	cout << Unbknapsack(wt, val, W, n) << endl;
}
