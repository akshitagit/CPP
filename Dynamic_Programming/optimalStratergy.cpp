#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std; 

int optimalGame(int *arr, int i, int j , unordered_map<string,int>& state){
	if(i>j) return 0 ; 

	string ans = to_string(i) +"|" + to_string(j) ; 
	if(state.find(ans) != state.end()){
		return state[ans]; 
	}

	int op1 = arr[i] + min(optimalGame(arr,i+1,j-1,state) , optimalGame(arr,i+2,j,state)); 
	int op2 = arr[j] + min(optimalGame(arr,i,j-2,state), optimalGame(arr,i+1,j-1,state)); 

	state[ans] = max(op1,op2); 
	return state[ans]; 
}

int optimalGame2(int* a ,int n){
    int DP[1000][1000]; //DP matrix
    memset(DP, 0, sizeof(DP));
    //base case
    for (int i = 0; i < n; i++) {
        DP[i][i] = a[i];
        if (i != n - 1) {
            DP[i][i + 1] = (a[i] > a[i + 1]) ? a[i] : a[i + 1];
        }
    }
    //filling up table using recursion
    for (int len = 2; len < n; len++) {
        for (int i = 0, j =len; j < n; i++, j++) {
        	int op1 = (i+2<n)?DP[i + 2][j]:0 ;
        	int op2 = (i+1<n)?DP[i + 1][j - 1]:0;
            DP[i][j] = max(a[i] + min(op1, op2), a[j] + min(op2, DP[i][j - 2]));
        }
    }
    //return result
    return DP[0][n - 1];
}

int main(){
	int t ; 
	cin >> t; 
	int arr[100];
	int n ; 
	while(t--)
	{
	    cin >> n; 
	    for(int i=0 ; i<n ; i++)
	    {
	        cin >> arr[i];
	    }
	    unordered_map<string,int> state; 
	    int ans = optimalGame( arr, 0,n-1,state); 
		int ans1 = optimalGame2(arr , n); 
		cout << ans1 << endl ;
	    cout << ans << endl ; 
	}
	return 0 ;
}


// Examples:
// Input:
// 2
// 4
// 5 3 7 10
// 4
// 8 15 3 7
// Output:
// 15
// 22