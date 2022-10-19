//Kickstart_2020_Round A_C

#include <iostream>
#include <cstdio>
#include <math.h>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#define pb push_back
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MAX 4001
#define DIV 100000LL
#define INF 2000000000
using namespace std;

int T, n, k, a[100001];

bool ok(int val) {
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		if (a[i + 1] - a[i] <= val) continue;
		if ((a[i + 1] - a[i]) % val == 0) {
			cnt += (a[i + 1] - a[i]) / val - 1;
		}
		else cnt += (a[i + 1] - a[i]) / val;
	}
	return cnt <= k;
}

int Bsearch() {
	int l = 1, r = (int)1e9 + 10;
	int mid, ans;
	while (l <= r) {
		mid = (l + r) / 2;
		//처리
		if (ok(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	return ans;
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> k;
		cin >> a[0];
		for (int i = 1; i < n; i++) {
			cin >> a[i];	
		}
		cout << "Case #" << tc << ": " << Bsearch() << "\n";
	}
	return 0;
}
