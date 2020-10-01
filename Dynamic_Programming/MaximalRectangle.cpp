/*
Algorithm:

1. Run a loop to traverse through the rows.
2. Now If the current row is not the first row then update the row as follows, if matrix[i][j] is not zero then matrix[i][j] = matrix[i-1][j] + matrix[i][j].
3. Find the maximum rectangular area under the histogram, consider the ith row as heights of bars of a histogram.
4. Do the previous two steps for all rows and print the maximum area of all the rows.

*/
/*
Example: 

Input:
0 1 1 0
1 1 1 1
1 1 1 1
1 1 0 0

Output :
1 1 1 1
1 1 1 1

Explanation : 
The largest rectangle with only 1's is from 
(1, 0) to (2, 3) which is
1 1 1 1
1 1 1 1 

*/

class Solution
{
public:
    int maxHist(int row[], int len)
    {
        stack<int> idx;
        int val, max_area = 0, cur_area = 0, i = 0;
        while (i < len)
        {
            if (idx.empty() || row[idx.top()] <= row[i])
            {
                idx.push(i++);
            }
            else
            {
                val = row[idx.top()];
                idx.pop();

                if (!idx.empty())
                    cur_area = val * (i - idx.top() - 1);
                else
                    cur_area = val * i;
                max_area = max(max_area, cur_area);
            }
        }
        while (!idx.empty())
        {
            val = row[idx.top()];
            idx.pop();
            if (!idx.empty())
                cur_area = val * (i - idx.top() - 1);
            else
                cur_area = val * i;
            max_area = max(max_area, cur_area);
        }
        return max_area;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int n = matrix.size();
        if (n == 0)
            return 0;
        int m = matrix[0].size();
        int height[10000] = {};
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '0')
                    height[j] = 0;
                else
                    height[j] += 1;
            }
            ans = max(ans, maxHist(height, m));
        }
        return ans;
    }
};