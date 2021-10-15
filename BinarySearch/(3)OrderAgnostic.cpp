#include<bits/stdc++.h>
using namespace std;

//order agnostic search
// array can be asc/desc sorted

int binarySearch(int a[], int n, int x, bool rev) {

	int s = 0;
	int e = n - 1;

	while (s <= e) {

		int mid = s + (e - s) / 2;

		if (a[mid] == x) return mid;
		else if (a[mid] > x && rev == true) s = mid + 1;
		else if (a[mid] > x && rev == false) e = mid - 1;
		else if (a[mid] < x && rev == true) e = mid - 1;
		else if (a[mid] < x && rev == false) s = mid + 1;

	}

	return -1;

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n;
	cin >> n;
	int a[n];
	int x; cin >> x;
	for (int i = 0; i < n; i++) cin >> a[i];

	if (a[0] > a[1]) cout << binarySearch(a, n, x, true) << endl;
	else cout << binarySearch(a, n, x, false) << endl;

}
