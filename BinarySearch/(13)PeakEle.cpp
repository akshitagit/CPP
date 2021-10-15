#include<bits/stdc++.h>
using namespace std;

// Binary Search on answer [ unsorted array kind of things but monotonic]
// Peak Element

int BinarySearch(int a[], int n, int s, int e) {

	while (s <= e) {

		int mid = s + (e - s) / 2;
		int prev = (mid - 1 + n) % n;
		int next = (mid + 1) % n;

		if (mid > 0 && mid < n - 1) {

			if (a[mid] > a[prev] && a[mid] > a[next]) {
				return mid;
			}

			if (a[mid] < a[mid + 1] ) s = mid + 1;
			else if (a[mid] > a[mid + 1]) e = mid - 1;
		}

		else if (mid == 0) {
			if (a[mid] > a[mid + 1]) return 0;
			else return 0;
		}

		else if (mid == n - 1) {
			if (a[mid] > a[mid - 1]) return mid;
			else return mid - 1;
		}

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

	cout << BinarySearch(arr, n, 0, n - 1) << endl; // index

}
