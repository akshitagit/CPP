#include<bits/stdc++.h>
using namespace std;

// first and last occurance of an element

int BS_1st(int a[], int n, int x) {

	int s = 0;
	int e = n - 1;
	int res = -1;

	while (s <= e) {

		int mid = s + (e - s) / 2;

		if (a[mid] == x) { // first occurance
			res = mid;
			e = mid - 1;
		}
		else if (a[mid] > x) e = mid - 1;
		else if (a[mid] < x) s = mid + 1;

	}
	return res;
}

int BS_last(int a[], int n, int x) {

	int s = 0;
	int e = n - 1;
	int res = -1;

	while (s <= e) {

		int mid = s + (e - s) / 2;

		if (a[mid] == x) { // last occurance
			res = mid;
			s = mid + 1;
		}
		else if (a[mid] > x) e = mid - 1;
		else if (a[mid] < x) s = mid + 1;

	}
	return res;
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

	cout << BS_1st(a, n, x) << " " << BS_last(a, n, x) << endl;

}
