#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
typedef vector<int> vi;
#define maxn 100005
vi v[maxn], vis(maxn, 0), col(maxn, -1);
int n, m;
int dfs(int st, int c)
{
    col[st] = c;
    vis[st]++;
    for (auto i = v[st].begin(); i != v[st].end(); i++)
    {
        if (!vis[*i])
        {
            if (!dfs(*i, c ^ 1))
                return 0;
        }
        else if (col[*i] == c)
            return 0;
    }
    return 1;
}
int32_t main()
{
    cin >> n >> m;
    for (int i = 0, x, y; i < m; i++)
    {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    cout << dfs(1, 0);
    return 0;
}
