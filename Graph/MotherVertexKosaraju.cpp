#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10];
vector<bool> vis(10,false);
stack <int> s;
void dfsKosa(int n)
{
    vis[n]=true;
    for(int j:adj[n])
    {
        if(vis[j]==false)
            dfsKosa(j);
    }
    s.push(n);
}
void dfs(int n)
{
    vis[n]=true;
    for(int i:adj[n])
        if(vis[i]==false)
            dfs(i);
}
int main()
{
    int p,c=0,v;
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[4].push_back(1);
    adj[6].push_back(4);
    adj[5].push_back(6);
    adj[5].push_back(2);
    adj[6].push_back(0);


    for(int i=0;i<=6;i++)
      if(vis[i]==false)
        dfsKosa(i);

    for(int i=0;i<=6;i++)
        vis[i]=false;

    v=s.top();
    dfs(v);

    for(int i=0;i<=6;i++)
        if(vis[i]==true)
         c++;

    if(c==7)
        cout << v; //output should be 5



}
