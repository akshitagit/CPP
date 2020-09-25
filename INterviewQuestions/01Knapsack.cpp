#include <bits/stdc++.h>
using namespace std;

// TIME COMPLEXITY : O(N*S)
// SPACE COMPLEXITY : O(N*S)

/*Algorithm
This problem can be solved using a dynamic programming approach. In a DP[][] table let’s consider all the possible weights from ‘1’ to ‘W’ as the columns and weights that can be kept as the rows.
The state DP[i][j] will denote maximum value of ‘j-weight’ considering all values from ‘1 to ith’. So if we consider ‘wi’ (weight in ‘ith’ row) we can fill it in all columns which have ‘weight values > wi’. Now two possibilities can take place:
1. Fill ‘wi’ in the given column.
2.Do not fill ‘wi’ in the given column.
Now we have to take a maximum of these two possibilities, formally if we do not fill ‘ith’ weight in ‘jth’ column then DP[i][j] state will be same as DP[i-1][j] but if we fill the weight, DP[i][j] will be equal to the value of ‘wi’+ value of the column weighing ‘j-wi’ in the previous row. So we take the maximum of these two possibilities to fill the current state.
The answer required will be computed in dp[N][S]
*/
int knapsack(int capacity, int itemsCount, vector<int> &itemSizes, vector<int> &itemValues)
{
    //constructing a DP table of size itemCount * capacity
    int dp[itemsCount + 1][capacity + 1];
    //dp[i][j] represents the maximum value that can be obtained by considering i items, and if we had a bag of capacity j
    //answer is dp[itemCount][capacity]
    memset(dp, 0, sizeof(dp));

    for (int items = 1; items <= itemsCount; items++)
    {
        for (int currCapacity = 1; currCapacity <= capacity; currCapacity++)
        {
            dp[items][currCapacity] = dp[items - 1][currCapacity];
            if (itemSizes[items - 1] <= currCapacity)
            {
                dp[items][currCapacity] = max(dp[items][currCapacity], itemValues[items - 1] + dp[items - 1][currCapacity - itemSizes[items - 1]]);
            }
        }
    }
    return dp[itemsCount][capacity];
}
int main()
{
    int capacity, itemCount;
    vector<int> itemSizes(itemCount, 0);
    vector<int> itemValues(itemCount, 0);

    cin >> itemCount >> capacity;
    for (int i = 0; i < itemCount; i++)
    {
        cin >> itemSizes[i];
    }
    for (int i = 0; i < itemCount; i++)
    {
        cin >> itemValues[i];
    }
    cout << knapsack(capacity, itemCount, itemSizes, itemValues) << endl;
    return 0;
}