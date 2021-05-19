// longest arithmetic progression subsequence #138
#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;

int longestAP (int set[], int n) { 
    if (n <= 2) return n;
    //create a table and init all vals as 2.
    int TBL[n][n]; 
    int lapLen = 2; 

    for (int i = 0; i < n; i++)
     TBL[i][n-1] = 2;
     // consider every element as second element of ap
     for ( int j=n-2; j >= 1; j--) {
         // search for i and k for j
         int i = j-1, k = j+1;
         while (i >= 0 && k <= n-1) {
             if (set[i] + set[k] < 2*set[j])
                k++;
            // before changing i set TBL[i][j] as 2
            else if (set[i] + set[k] > 2*set[j]) {
                TBL[i][j] =2, i--;
            } else {
                // found i and k for j, lapLen with i and j as the first two elements 
                // are equal to lapLen with j and k as the first two elements +1
                TBL[i][j] = TBL[j][k] +1;
                // update overall lapLen if needed
                lapLen = max(lapLen, TBL[i][j]);
                // change i and k to fill more TBL[i][j] values for current j
                i--; k++;
            }
         }
         // set remaining enitites in  collum j as 2
         while (i >= 0) {
             TBL[i][j] = 2;
             i--;
         }
     }
     return lapLen;
}  
// this function improves space complexity from O(h) -> O(n)
int improvedSpaceSol (vector<int> A) { 
    int len = 2; 
    int n = A.size();
    if (n <= 2) return n;
    vector<int> ap(n, 2);
    sort(A.begin(), A.end());

    for (int j = n-2; j >= 0; j--) {
        int i = j-1;
        int k = j+1;
        while ( i >= 0 && k < n) {
            if(A[i] + A[k] == 2 * A[j]){
                ap[j] = max(ap[k] + 1, ap[j]);
                len = max(len, ap[j]);
                i -= 1;
                k += 1;
            } else if (A[i] + A[k] < 2 * A[j]) {
                k += 1;
            } else {
                i -= 1;
            }
        }
    }
    return len;
}
// this function using vector<vector<int> is faster then other 2d / x_map approaches.
int lasl (vector<int> A) {
    int len = 2; int n = A.size();
    vector<vector<int>> dp(n, vector<int>(2000,0));
    for (int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int dif = A[j] - A[i] + 1000;
            dp[j][dif] = max(2, dp[i][dif] +1 );
            len = max(len, dp[j][dif]);
        }
    }
    return len;
}
// tests
int main() {
    cout << "first approach in O(n^2) time & O(n^2) space\n";
    int set[] = {1, 7, 10, 13, 14, 19}; 
    int n1 = sizeof(set)/sizeof(set[0]); 
    cout <<  longestAP(set, n1) << endl; 
  
    cout << "improved approach in O(n^2) time & O(n) space\n";
    vector<int>set2({1, 7, 10, 13, 14, 19});
    cout << improvedSpaceSol(set2) << endl;

    cout << "vector of vector runs faster but idk wh..\n";
    vector<int>set3({1, 3, 5, 7, 9, 30});
    cout << lasl(set2) << endl;
    return 0;
}