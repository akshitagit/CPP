#include<bits/stdc++.h>
using namespace std;

// Allocate minimum number of pages

bool isValid(int a[], int n, int k, int mid) {

	int student = 1;
	int sum = 0;

	for (int i = 0; i < n; i++) {

		sum += a[i];
		if (sum > mid) {
			student ++;
			sum = a[i];
		}
	}

	if (student > k) return false;
	return true;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	int a[n];

	int sum = 0 ;
	int mx = INT_MIN;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
		mx = max(mx, a[i]);
	}

	int s = mx;
	int e = sum;
	int res = -1;

	while (s <= e) {

		int mid = s + (e - s) / 2;

		if (isValid(a, n, k, mid) == true) {
			res = mid;
			e = mid - 1;
		}
		else s = mid + 1;
	}

	cout << res << endl;

}
