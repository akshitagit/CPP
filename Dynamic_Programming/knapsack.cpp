#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
typedef vector<int> vi;
#define maxn 100005
int dp[101][maxn];
int32_t main()
{
  int n, W;
  cin >> n >> W;
  vi val(n + 1), wt(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> wt[i] >> val[i];
  for (int i = 1; i <= n; i++)
  {
    for (int w = 1; w <= W; w++)
    {
      if (wt[i] > w)
        dp[i][w] = dp[i - 1][w];
      else
      {
        dp[i][w] = max(dp[i - 1][w - wt[i]] + val[i], dp[i - 1][w]);
      }
    }
  }
  cout << dp[n][W];
  return 0;
}
