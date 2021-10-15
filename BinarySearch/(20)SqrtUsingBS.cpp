#include<bits/stdc++.h>
using namespace std;

// Finding square of a number with precesion
// Coding blocks

float FindSqrt(int n, int p) {

	int int_part = 0;
	int s = 0, e = n;

	while (s <= e) {

		int mid = s + (e - s) / 2;

		if (mid * mid <= n) {
			int_part = mid;
			s = mid + 1;
		}
		else if (mid * mid > n) {
			e = mid - 1;
		}
	}

	// return int_part;

	float frac_part = 0;
	float inc = 0.1;
	float ans = int_part;

	for (int i = 0; i < p; i++) {

		while (ans * ans <= n) {
			ans += inc;
		}
		ans = ans - inc;
		inc = inc / 10;
	}

	return ans;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, p;
	cin >> n >> p;

	cout << FindSqrt(n, p) << endl;

}
