// https://www.geeksforgeeks.org/connected-components-in-an-undirected-graph/

#include<bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> graph[10001];
vector<bool> visited(10001);

void dfs(int u){
    visited[u] = true;
    for(int x: g[u]){
        if(!visited[x]){
            visited[x]=true;
            dfs(x);
        }
    }
}

int connected_components(int n){
    
    memset(visited, false, sizeof(visited));
    int number_of_connected_components=0;

    for(int i=0;i<n;i++){
        if(!visited[i])
        {
            dfs(i);
            number_of_connected_components++;
        }
    }

    return number_of_connected_components;
}

int main(){

    cin >> n >> m;
    for (int i = 0, x, y; i < m; i++)
    {
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    cout << connected_components(n);
    return 0;
}