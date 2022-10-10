#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    vector<int> adj[n + 1];
    // for weighted graph  us the following line of code ;
    // vector<pair<int, int>> adj[n+1] ;
    for (int i = 0; i < m; i++)
    {
        int u, v; // wt
        cin >> u >> v;

        //   for weighted graph
        // cin>>u>>v>>wt ;
        // adj[u].push_back({v,wt});
        // adj[u].push_back({u,wt});

        adj[u].push_back(v);
        adj[v].push_back(u); // for directed graph omit this line
    }

    for (int i = 0; i < n + 1; i++)
    {
        for (auto x : adj[i])
            cout << x << " ";
        cout << endl;
    }
    return 0;
}