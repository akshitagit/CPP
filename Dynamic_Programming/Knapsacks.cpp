#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const int MX = 3e5 + 5;
#define endl "\n"
//__________________________________________________________________

// Not traditional 0/1 Knapsack

ll a[1001];
ll wt[1001];
ll weird(ll n, ll w, ll sum) {
	ll dp[n+1][sum+1];

	for(int i = 0; i<sum+1; i++) dp[0][i] = INF;
	for(int i = 0; i<n+1; i++) dp[i][0] = 0;
	
	for(int i = 1; i<n+1; i++) {
		for(int j = 1; j<sum+1; j++) {
			
			if(a[i-1] <= j) // Min Weight s.t. Value is maximized
				dp[i][j] = min(wt[i-1] + dp[i-1][j-a[i-1]], dp[i-1][j]);
			
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	ll res = 0;
	for(int i = sum; i>=0; i--) {    // Searching for max val s.t. wt is less than capacity
		if(dp[n][i]<=w) {
			res = i;
			break;
		}
	}

	return res;
}

int main(){
	ll n, w, sum = 0; cin>>n>>w;
	for(int i = 0; i<n; i++) {
		cin>>a[i];
		sum += a[i];
	}
	for(int i = 0; i<n; i++) cin>>wt[i];
	cout<<weird(n, w, sum);
}

//__________________________________________________________________
/*
Sample Input:
4 20
10 2 1 3
10 5 10 10

Sample Output:
13

*/
