//number of unique paths to reach from starting to bottom right of the board when only right and downwards directions are allowed
#include<bits/stdc++.h>
using namespaces std;

 int uniquePaths(int m, int n) {
        
        int dp[m][n];
        
        for(int i=0;i<m;i++){
            dp[i][0]=1;
        }
        
         for(int i=1;i<n;i++){
            dp[0][i]=1;
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]= dp[i-1][j]+dp[i][j-1];
            }
        }
       return dp[m-1][n-1];
}

int main(){
  int r, c; //r- row, c-column
  cin>>r>>c;
  cout<<uniquePaths(r,c);
   return 0;
}
