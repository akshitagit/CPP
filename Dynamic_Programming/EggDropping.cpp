/*
@cpp file
@01/10/20
*/

#include<bits/stdc++.h>
#include "string"
using namespace std;

int superEggDrop(int K, int N) {
       vector<vector<int> > dp(1, vector<int>(K+1));
        int move = 0;
        while (dp[move][K] < N)
        {
            move++;
            if (dp.size() == move)
                dp.push_back(vector<int>(K+1));

            for (int i = 1; i <= K; ++i)
                dp[move][i] = dp[move-1][i-1] + dp[move-1][i] + 1;
        }
        return move;
}

int main()
{

    int K,N;
    cout << "Enter Eggs(K) : ";
    cin >> K;
    cout << "Enter Floors(N) : ";
    cin >> N;
 
    cout << "Minium Number of Moves --> " << superEggDrop(K,N) << endl;
    return 0;
}

/*
K = 1, N = 2
Output: 2
Explanation: 
Drop the egg from floor 1.  If it breaks, we know with certainty that F = 0.
Otherwise, drop the egg from floor 2.  If it breaks, we know with certainty that F = 1.
If it didn't break, then we know with certainty F = 2.
Hence, we needed 2 moves in the worst case to know what F is with certainty.
*/