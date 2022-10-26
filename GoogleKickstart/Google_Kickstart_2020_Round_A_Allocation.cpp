//Kickstart_2020_Round A_A

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

int T, n, b, a[100001];

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> n >> b;
		int cnt = 0;
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		for (int i = 0; i < n; i++) {
			if (b < a[i]) break;
			cnt++;
			b -= a[i];
		}
		cout << "Case #" << tc << ": " << cnt << "\n";
	}
}
