#include<bits/stdc++.h>
using namespace std;
int t[100][100];

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

	int wt[] = {1, 3, 4, 1};
	int Sum = 5;
	int n = sizeof(wt) / sizeof(int);
	cout << CountSubsetGivenSum(wt, Sum, n) << endl; // considers all subsets so some are same
}
