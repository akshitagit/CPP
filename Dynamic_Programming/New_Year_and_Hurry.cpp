/*Limak is going to participate in a contest on the last day of the 2016.
The contest will start at 20:00 and will last four hours, exactly until midnight.
There will be n problems, sorted by difficulty, i.e. problem 1 is the easiest and problem n is the hardest.
Limak knows it will take him 5·i minutes to solve the i-th problem.
Limak's friends organize a New Year's Eve party and Limak wants to be there at midnight or earlier.
He needs k minutes to get there from his house, where he will participate in the contest first.
How many problems can Limak solve if he wants to make it to the party?

Input
The only line of the input contains two integers n and k

Output
Print one integer, denoting the maximum possible number of problems Limak can solve so that he could get to the party at midnight or earlier.*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int time_left = 240 - k;
    int dp[time_left + 10];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; ++ i)
        for(int j = time_left; j >= i * 5; -- j)
        {
           dp[j] = max(dp[j], dp[j - i * 5] + 1) ;
        }
    cout << dp[time_left] << endl;
    return 0;
}

