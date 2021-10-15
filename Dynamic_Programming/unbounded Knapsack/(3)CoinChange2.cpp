#include<bits/stdc++.h>
using namespace std;
int t[100][100];

// minimum number of coins to make sum

int Unbknapsack(int *wt, int W, int n) {

	for (int i = 0; i <= n; i++) t[i][0] = 0;
	for (int i = 0; i <= W; i++) t[0][i] = INT_MAX - 1;
	for (int i = 1; i <= W; i++) {
		if (i % wt[0] == 0)  t[1][i] = i / wt[0];
		else t[1][i] = INT_MAX - 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= W; j++) {

			if (wt[i - 1] <= j) {
				t[i][j] = min( 1 + t[i][j - wt[i - 1]] , t[i - 1][j]);
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
