
#include <bits/stdc++.h>

using namespace std;

int N;
int arr[505][505];
int tmp[505][505];
int cst[505][505];
int row[505];
int col[505];
int dsu[1005];

int getrt(int n){
	return dsu[n] = (dsu[n] == n ? n : getrt(dsu[n]));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for(int x = 1; x <= t; x++){
		cin >> N;
		for(int i =1 ; i<=N; i++){
			for(int j = 1; j<=N; j++){
				cin >> arr[i][j];
			}
		}
		for(int i= 1; i<=2*N; i++){
			dsu[i] = i;
		}
		long long ans = 0;
		priority_queue<pair<int, pair<int, int>>> pq;
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=N; j++){
				cin >> cst[i][j];
				if(arr[i][j] == -1){
					ans += cst[i][j];
					pq.push(make_pair(cst[i][j], make_pair(i, j+N)));
				}
			}
		}
		while(pq.size()){
			auto p = pq.top();
			pq.pop();
			if(getrt(p.second.first) != getrt(p.second.second)){
				dsu[getrt(p.second.first)] = getrt(p.second.second);
				ans -= p.first;
			}
		}
		for(int i = 1; i<=N; i++){
			cin >> row[i];
		}
		for(int j = 1; j<=N; j++){
			cin >> col[j];
		}
		cout << "Case #" << x << ": " << ans << "\n";
	}
}