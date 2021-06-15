#include <bits/stdc++.h>

using namespace std;

int arr[1005][1005];
int lft[1005][1005];
int up[1005][1005];
int rht[1005][1005];
int down[1005][1005];

long long solve(long long a, long long b){
	return max(0LL, min(a/2-1, b-1)) + max(min(b/2-1, a-1), 0LL);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for(int x = 1; x <= t; x++){
		int N, M;
		cin >> N >> M;
		for(int i = 0; i<=N+1; i++){
			for(int j = 0; j<=M+1; j++){
				down[i][j] = up[i][j] =rht[i][j] = lft[i][j] = 0;
			}
		}
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				cin >> arr[i][j];
			}
		}
		for(int i = 1; i<=N; i++){
			for(int j =1 ; j<=M; j++){
				lft[i][j] = lft[i][j-1]*arr[i][j] + arr[i][j];
			}
		}
		for(int i = 1; i<=N; i++){
			for(int j = M; j; j--){
				rht[i][j] = rht[i][j+1]*arr[i][j] + arr[i][j];
			}
		}
		for(int i = 1; i<=N; i++){
			for(int j =1 ; j<=M; j++){
				up[i][j] = up[i-1][j]*arr[i][j] + arr[i][j];
			}
		}
		for(int i = N; i; i--){
			for(int j =1 ; j<=M; j++){
				down[i][j] = down[i+1][j]*arr[i][j] + arr[i][j];
			}
		}
		long long ans = 0;
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				if(!arr[i][j]){
					continue;
				}
				ans += solve(lft[i][j], up[i][j]);
				ans += solve(rht[i][j], up[i][j]);
				ans += solve(lft[i][j], down[i][j]);
				ans += solve(rht[i][j], down[i][j]);
			}
		}
		cout << "Case #" << x << ": " << ans << "\n";
	}
}