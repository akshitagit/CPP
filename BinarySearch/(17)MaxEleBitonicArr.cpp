#include<bits/stdc++.h>
using namespace std;

// Max element in bitonic array [inc-peak-dec]

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

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];

	cout << arr[Peak(arr, n)];
}
