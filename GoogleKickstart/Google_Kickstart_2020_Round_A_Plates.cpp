//Kickstart_2020_Round A_B

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

int T, n, k, p, a[31], dp[1501];
int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		vector<pii> v;
		cin >> n >> k >> p;
		for (int i = 0; i < n; i++) {
			memset(a, 0, sizeof(a));
			for (int j = 1; j <= k; j++) {
				cin >> a[j];
				a[j] += a[j - 1];
				v.pb({ a[j], j });
			}
		}
		int sz = v.size();
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) {
			for (int cnt = p; cnt >= 0; cnt--) {
				for (int j = 0; j < k; j++) {
					int idx = i * k + j;
					if (v[idx].second > cnt) continue;
					dp[cnt] = max(dp[cnt], dp[cnt - v[idx].second] + v[idx].first);
				}
			}
		}
		/*
		for (int i = 0; i < sz; i++) {
			for (int cnt = p; cnt >= v[i].second; cnt--) {
				dp[cnt] = max(dp[cnt], dp[cnt - v[i].second] + v[i].first);
			}
		}*/
		int mx = 0;
		for (int cnt = 0; cnt <= p; cnt++) mx = max(mx, dp[cnt]);
		cout << "Case #" << tc << ": " << mx << "\n";
	}
	return 0;
}
