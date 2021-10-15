#include<bits/stdc++.h>
using namespace std;

// find an element in nearly soretd array
// Element that will be present at ith index in sorted array can be at [i-1 , i, i+1]th index

int BinarySearch(int a[], int x, int s, int e) {

	while (s <= e) {

		int mid =  s + (e - s) / 2;

		if (a[mid] == x) return mid;
		if (a[mid - 1] == x && (mid - 1) >= s) return mid - 1;
		if (a[mid + 1] == x && (mid + 1) <= e) return mid + 1;

		else if (a[mid] > x) e = mid - 2;
		else if (a[mid] < x) s = mid + 2;
	}
	return -1;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n, x;
	cin >> n >> x;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i]; // nearly sorted array

	cout << BinarySearch(arr, x, 0, n - 1) << endl;

}
