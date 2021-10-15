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


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int wt[] = {0, 2, 4, 3};
	int n = sizeof(wt) / sizeof(int);
	int Range = 0;
	for (int i = 0; i < n; i++) Range += wt[i];
	SubsetSum(wt, Range, n); // to create dp table
	vector<int> v;

	for (int i = 0; i <= Range / 2; i++) {
		if (t[n][i] == true) {
			v.push_back(i);
		}
	}

	int last = INT_MIN;

	for (int i = 0; i < v.size(); i++) {
		if (last < v[i]) last = v[i];
	}

	int ans = Range - 2 * last;
	cout << ans << endl;

}
