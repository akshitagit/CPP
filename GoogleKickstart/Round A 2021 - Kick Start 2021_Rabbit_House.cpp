#include <bits/stdc++.h>

using namespace std;

int N, M;
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int arr[305][305];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for(int x = 1; x <= t; x++){
		cin >> N >> M;
		priority_queue<pair<int, pair<int, int>>> pq;
		for(int i = 1; i<=N; i++){
			for(int j = 1; j<=M; j++){
				cin >> arr[i][j];
				pq.push(make_pair(arr[i][j], make_pair(i, j)));
			}
		}
		long long ans = 0;
		while(pq.size()){
			auto p = pq.top();
			pq.pop();
			if(arr[p.second.first][p.second.second] != p.first){
				continue;
			}
			int i = p.second.first;
			int j = p.second.second;
			for(int m = 0; m<4; m++){
				if(dx[m]+i && dx[m]+i <= N && dy[m]+j && dy[m]+j <= M &&
				arr[dx[m]+i][dy[m]+j] < arr[i][j]-1){
					ans += arr[i][j] - 1-arr[dx[m]+i][dy[m]+j];
					arr[dx[m]+i][dy[m]+j] = arr[i][j] - 1;
					pq.push(make_pair(arr[dx[m]+i][dy[m]+j], make_pair(dx[m]+i, dy[m]+j)));
				}
			}
		}
		cout << "Case #" << x << ": " << ans << "\n";
	}
}