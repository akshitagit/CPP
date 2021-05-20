#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
const int inf =(int)(2e9);
const int MAX = 1e8;
int memo[MAX];
int main() {
    fastIO;
    int n;
    cin>>n;
	int sum=0;
	int best =-inf;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		sum+=a[i];
		best=max(best,sum);
		if(sum<0) sum=0;
	}
    cout<<best<<endl;
    return 0;
}


