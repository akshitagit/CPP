#include<bits/stdc++.h>
using namespace std;

// Next Alphabet (kindof ceil in terms of ascii)

char BinarySearch(char a[], int x, int s, int e) {

	char res = '#';
	while (s <= e) {

		int mid =  s + (e - s) / 2;

		if (a[mid] == x) return a[mid]; // or a[mid+1] for next element

		if (a[mid] < x) {
			s = mid + 1;
		}

		else if (a[mid] > x) {
			res = a[mid];
			e = mid - 1;
		}

	}
	return res;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int n;
	char x;
	cin >> n >> x;
	char arr[n];
	for (int i = 0; i < n; i++) cin >> arr[i];

	cout << BinarySearch(arr, x, 0, n - 1) << endl;

}
