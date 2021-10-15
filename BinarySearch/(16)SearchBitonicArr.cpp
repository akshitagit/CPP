#include<bits/stdc++.h>
using namespace std;

// Search in bitonic array [inc-peak-dec]

int Peak(int a[], int n) {

	int s = 0;
	int e = n - 1;

	while (s <= e) {

		int mid = s + (e - s) / 2;
		int prev = (mid - 1 + n) % n;
		int next = (mid + 1) % n;

		if (a[mid] > a[prev] && a[mid] > a[next]) return mid;
		else if (a[mid] < a[mid + 1]) s = mid + 1;
		else if (a[mid] > a[mid + 1]) e = mid - 1;
	}
}

int BinarySearch_Asc(int a[], int n, int x, int s, int e) {

	while (s <= e) {

		int mid = s + (e - s) / 2;
		if (a[mid] == x) return mid;
		else if (a[mid] > x) e = mid - 1;
		else if (a[mid] < x) s = mid + 1;
	}
	return -1;
}

int BinarySearch_Des(int a[], int n, int x, int s, int e) {

	while (s <= e) {

		int mid = s + (e - s) / 2;
		if (a[mid] == x) return mid;
		else if (a[mid] < x) e = mid - 1;
		else if (a[mid] > x) s = mid + 1;
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
	for (int i = 0; i < n; i++) cin >> arr[i];

	int i = Peak(arr, n);

	int a = BinarySearch_Asc(arr, n, x, 0, i);
	int b = BinarySearch_Des(arr, n, x, i + 1, n - 1);

	if (a == -1 && b == -1) cout << "-1" << endl;
	else if (a == -1) cout << b << endl;
	else if (b == -1) cout << a << endl;

}
