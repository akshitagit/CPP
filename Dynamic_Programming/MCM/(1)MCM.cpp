#include<bits/stdc++.h>
using namespace std;
int t[100][100];

// Matrix Chain Multiplication - MCM [on string / array]
// Break at each k
// Minimize cost to multiply matrix

int solve(int a[], int i, int j) {

// Ai = a[i-1]*a[i] matrix m*n
	int ans = INT_MAX;

	if (i >= j) return 0;

	for (int k = i; k <= j - 1; k++) {

		int temp_ans = solve(a, i, k) + solve(a, k + 1, j) + a[i - 1] * a[k] * a[j];
		ans = min(temp_ans, ans);

	}

	return ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a[] = {2, 3, 4, 6};
	int n = sizeof(a) / sizeof(int);

	cout << solve(a, 1, n - 1) << endl;


}
