/*Square Root Decomposition
Helps us to reduce the complexity by sqrt(n)
1. The idea is to divide the array into block of size
sqrt(n) (approximately)
Like for n = 10, Blocks would be 3,3,3,1
(Dummy values can be inserted in block with 1  element)
2.Compute answer for every block and store in " " array
3. Given a query from L to R, combine answers for all
blocks in the range L to R
*/
// Range Sum Query problem with updates
// Complexities: Update: O(1), Query: O(sqrt(n))

#include<bits/stdc++.h>
using namespace std;

int query(int *blocks, int *arr, int L, int R, int rn) {

	int ans = 0;
	//Left part of query,
	while (L % rn != 0 and L != 0 and L < R) {
		ans += arr[L++];
	}
	//middle part
	while (L + rn <= R) {

		int block_id = L / rn;
		ans += blocks[block_id];
		L += rn;

	}
	while (L <= R)
	{
		ans += arr[L];
		L++;
	}
	return ans;

}

void update(int *blocks, int *arr, int i , int val, int rn) {

	int block_id = i / rn;
	blocks[block_id] += val - arr[i];
	arr[i] = val;
}


int main() {

	int a[] = {1, 3, 5, 2, 7, 6, 3, 1, 4, 8 };
	int n = sizeof(a) / sizeof(a[0]);

	//Building the blocks array

	int rn = sqrt(n);
	int *blocks = new int[rn + 1] {0};
	int block_id = -1;

	for (int i = 0; i < n; i++) {

		if (i % rn == 0) {
			//At every multiple of rn, block id is incremented
			block_id++;
		}
		blocks[block_id] += a[i];
	}

	//Query
	cout << query(blocks, a, 2, 8, rn) << endl;
	//update
	update(blocks, a, 2, 15, rn);
	cout << query(blocks, a, 2, 8, rn) << endl;


}


