#include<bits/stdc++.h>
using namespace std;

// Search in row-wise and col-wise sorted 2D array

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n, m, x;
	cin >> n >> m >> x;
	int a[n][m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	int s = 0, e = m - 1;
	int flag = 0;

	while (s >= 0 && s < n && e >= 0 && e < n) {

		int mid = a[s][e];

		if (mid == x) {
			cout << "found at " << "(" << s << "," << e << ")" << endl;
			flag = 1;
			break;
		}

		else if (mid < x) {
			s = s + 1;
		}
		else if (mid > x) {
			e = e - 1;
		}
	}

	if (!flag) cout << "Not found" << endl;


}
