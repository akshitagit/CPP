#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10];
vector<bool> vis(10,false);
stack <int> s;
vector<int> radj[10];
queue<int> q;
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
void greverse(int n)
{
    for(int i:adj[n])
        radj[i].push_back(n);
}
void Connected()
{
    int comp=0;
    vector<int> ids(10,-1);
    while(!s.empty())
    {   int p,r;
        p=s.top();
        s.pop();
        if(ids[p]!=-1)
            continue;

        cout << "comp[" << comp+1 << "]: ";
        ids[p]=comp;
        q.push(p);
        while(!q.empty())
        {
            r=q.front();
            q.pop();
            cout << r << " ";
            for(int j:radj[r])
            {
                if(ids[j]==-1)
                { ids[j]=comp;
                  q.push(j);
                }
            }
        }
        cout << "\n";
        comp++;
    }
}
int main()
{

    //adj[8].push_back(10);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(5);
    adj[3].push_back(4);
    adj[4].push_back(6);
    adj[5].push_back(6);
    adj[6].push_back(8);
    adj[7].push_back(6);
    adj[8].push_back(7);



    for(int i=1;i<=8;i++)
      if(vis[i]==false)
        dfsKosa(i);

   for(int i=1;i<=8;i++)
       greverse(i);

    Connected();
}
