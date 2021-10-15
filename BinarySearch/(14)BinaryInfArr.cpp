#include<bits/stdc++.h>
using namespace std;

// First occurance of 1 in binary sorted array [0000...1111...]

int BinarySearch(int a[], int n, int s, int e) {

	int res = -1;
	while (s <= e) {

		int mid = s + (e - s) / 2;

		if (a[mid] == 1) {
			res = mid;
			e = mid - 1;
		}

		if (a[mid] < 1 ) s = mid + 1;
		else if (a[mid] > 1) e = mid - 1;
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
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];

	int s = 0, e = 1;

	while (1 > arr[e]) {
		s = e;
		e = e * 2;
	}

	cout << BinarySearch(arr, n, s, e) << endl; // index

}
