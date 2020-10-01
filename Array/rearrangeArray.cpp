#include <bits/stdc++.h>
using namespace std;

void assign(int a[], int n)
{
	// Sort the array
	sort(a, a + n);

	int ans[n];
	int p = 0, q = n - 1;
	for (int i = 0; i < n; i++) {
		// Assign even indexes with maximum elements
		if ((i + 1) % 2 == 0)
			ans[i] = a[q--];

		// Assign odd indexes with remaining elements
		else
			ans[i] = a[p++];
	}

	// Print result
	for (int i = 0; i < n; i++)
		cout << ans[i] << " ";
}

int main()
{
	int A[] = { 1, 3, 2, 2, 5 };
	int n = sizeof(A) / sizeof(A[0]);
	assign(A, n);
	return 0;
}
