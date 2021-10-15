#include<bits/stdc++.h>
using namespace std;
int t[100][100];

// LeetCode Target sum ques
int CountSubsetGivenSum(int *wt, int Sum, int n) {


	for (int i = 0; i <= Sum; i++) t[0][i] = 0;
	for (int i = 0; i <= n; i++) t[i][0] = 1; //empty set


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= Sum; j++) {

			if (wt[i - 1] <= j) {
				t[i][j] = (t[i - 1][j - wt[i - 1]] + t[i - 1][j]);
			}
			else {
				t[i][j] = t[i - 1][j];

			}
		}

	}
	return t[n][Sum];
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int wt[] = {1, 2, 4};
	int diff = 3;
	int range = 0;
	int n = sizeof(wt) / sizeof(int);
	for (int i = 0; i < n; i++) range += wt[i];
	int S1 = (diff + range) / 2; // diff+range should be even else ans=0
	cout << CountSubsetGivenSum(wt, S1, n) << endl;
}

