#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for(int x = 1; x <= t; x++){
		int N, K;
		string s;
		cin >> N >> K >> s;
		int cnt = 0;
		for(int i = 0; i<N/2; i++){
			cnt += (s[i] != s[N-i-1]);
		}
		cout << "Case #" << x << ": " << abs(cnt - K) << "\n";
	}
}