#include<bits/stdc++.h>
using namespace std;

// position of an element in an infinite sorted array

int BinarySearch(int a[], int x, int s, int e) {

	while (s <= e) {
		int mid = s + (e - s) / 2;

		if (a[mid] == x) return mid;

		else if (a[mid] > x) e = mid - 1;
		else if (a[mid] < x) s = mid + 1;
	}
	return -1;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n;
	int x;
	cin >> n >> x;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];

	int s = 0, e = 1;
	while (x > arr[e]) {
		s = e;
		e = e * 2;
	}

	cout << BinarySearch(arr, x, s, e) << endl;

}
