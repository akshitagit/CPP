#include<bits/stdc++.h>
using namespace std;

// find an element in rotated sorted array

int CountRotations(int a[], int n) {

	int s = 0;
	int e = n - 1;

	while (s <= e) {

		int mid = s + (e - s) / 2;
		int next = (mid + 1) % n;
		int prev = (mid - 1 + n) % n;

		if ((a[mid] <= a[next]) && (a[mid] <= a[prev])) {
			return mid;
		}

		// else if(arr[mid]>arr[0])
		// low=mid+1;
		// else if(arr[mid]<arr[n-1])
		// high=mid-1;
		// else
		// low=mid+1;

		else if (a[mid] > a[mid + 1]) s = mid + 1;
		else if (a[mid] < a[mid + 1]) e = mid - 1;

		// if (a[s] <= a[mid]) s = mid + 1;
		// else if (a[mid] <= a[e]) e = mid - 1;

	}
}

int BinarySearch(int a[], int n, int x, int s, int e) {

	while (s <= e) {

		int mid =  s + (e - s) / 2;

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


	int n, x;
	cin >> n >> x;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i]; // rotated sorted array

// array should be atleast once rotated
	int i = CountRotations(arr, n);
	cout << i << endl;

	int a = BinarySearch(arr, n, x, 0, i - 1);
	int b = BinarySearch(arr, n, x, i, n - 1);

	// cout << i << " " << a << " " << b << endl;

	if (a == -1 && b == -1) cout << "-1" << endl;
	else if (a == -1) cout << b << endl;
	else if (b == -1) cout << a << endl;

}
