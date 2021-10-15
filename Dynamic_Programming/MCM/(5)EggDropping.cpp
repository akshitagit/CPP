#include<bits/stdc++.h>
using namespace std;

// Egg dropping problem
// Minimum number of attempts in worst case to find threshold floor of building

int solve(int e, int f) {

	if (e == 1) return f; // with one egg worst case
	if (f == 0 || f == 1) return f;

	int ans = INT_MAX;

	for (int k = 1; k <= f; k++) { // 1 to f floors

		int temp = 1 + max(solve(e - 1, k - 1), solve(e, f - k));
		ans = min(ans, temp);
	}

	return ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int e = 3;
	int f = 5;

	cout << solve(e, f) << endl;

}
