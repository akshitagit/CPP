#include<bits/stdc++.h>
using namespace std;
bool t[100][100];

bool SubsetSum(int *wt, int Sum, int n) {


	for (int i = 0; i <= Sum; i++) t[0][i] = false;
	for (int i = 0; i <= n; i++) t[i][0] = true; //empty set


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= Sum; j++) {

			if (wt[i - 1] <= j) {
				t[i][j] = (t[i - 1][j - wt[i - 1]] || t[i - 1][j]);
			}
			else {
				t[i][j] = t[i - 1][j];

			}
		}


	}
	return t[n][Sum];
}

bool EqSumPartition(int *wt, int n) {
	int s = 0;
	for (int i = 0; i < n; i++) s += wt[i];

	if (s % 2 != 0) return false;
	else SubsetSum(wt, s / 2, n);
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int wt[] = {2, 6, 4, 10};
	int n = sizeof(wt) / sizeof(int);
	cout << EqSumPartition(wt, n) << endl;
}
