#include<bits/stdc++.h>
using namespace std;
int t[100][100];

// maximum number of ways

int Unbknapsack(int *wt, int W, int n) {

	for (int i = 0; i <= W; i++) t[0][i] = 0;
	for (int i = 0; i <= n; i++) t[i][0] = 1;


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= W; j++) {

			if (wt[i - 1] <= j) {
				t[i][j] = t[i][j - wt[i - 1]] + t[i - 1][j];
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

	int coins[] = {1, 2, 3};
	int W = 5;
	int n = sizeof(coins) / sizeof(int);
	cout << Unbknapsack(coins, W, n) << endl;
}
