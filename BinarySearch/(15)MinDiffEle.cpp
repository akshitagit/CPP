#include<bits/stdc++.h>
using namespace std;

// if key present return key
// else return minimum absolute difference element from x in a sorted array

// Concept:- When element is not present , binary search ends with s,e as neighbours of key

int BinarySearch(int a[], int n, int x) {

	int s = 0;
	int e = n - 1;

	while (s <= e) {

		int mid = s + (e - s) / 2;

		if (a[mid] == x) {
			return a[mid];
		}

		if (a[mid] < x ) s = mid + 1;
		else if (a[mid] > x) e = mid - 1;
	}

	return (abs(a[s] - x) > abs(a[e] - x)) ? a[e] : a[s];

}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n, x;
	cin >> n >> x;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];

	cout << BinarySearch(arr, n, x) << endl;

}
