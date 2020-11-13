#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std ;

int mcm(vector<int>& A){
	int dp[200][200]; 
	memset(dp,0,sizeof dp); 
	int n = A.size() -1 ;
	for(int i=1 ; i<n ;i++){
		int r=0 , c=i ;
		while(c<n){
			int val = INT_MAX; 
			for(int pivot = r; pivot<c ;pivot++){
               val = min(val,dp[r][pivot] + dp[pivot+1][c] + A[r]*A[pivot+1]*A[c+1]);
			}
			dp[r][c] = val ;
			r++ , c++ ; 
		}
	}

	return dp[0][n-1];
}
int main(){
	int n ;
	cin >> n ; 
	vector<int> v(n,0); 
	for(int i=0 ;i<n; i++){
		cin >> v[i];
	}
	int ans = mcm(v); 
	cout << ans << endl; 
	return 0; 
}