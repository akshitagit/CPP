#include <bits/stdc++.h>

using namespace std;

vector<int> dist;
vector<int> *adj;
vector<bool> visited;

void BFS(int s,vector<int> *a,vector<bool>visited)
{
    visited[s]=true;
    queue<int> q;
   
    q.push(s);
    while(!q.empty()){
        s=q.front();
        q.pop();
        for(int i:a[s])
         {
        
            if(!visited[i] && dist[i]==-1)
            {
                dist[i]=dist[s]+1;
                visited[i]=true;
                q.push(i);
            }
         }
    }
}

int main()
{
    int no;
    cin>>no;
    while(no--)
    {
        int m,n;
        cin>>n>>m;

        adj=new vector<int>[n];
        for(int i=0; i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            adj[x-1].push_back(y-1);
            adj[y-1].push_back(x-1);
        }
        int s;
        cin>>s;
        visited.assign(n+1,false);
        dist.resize(n,-1);
         dist[s-1]=0;
        BFS(s-1,adj,visited);
        for(int i=0; i<dist.size(); i++)
        {
            if(dist[i]==-1)
                cout<<dist[i]<<" ";
            else if(dist[i]!=0)
                cout<<dist[i]*6<<" ";
        }
        cout<<endl;
        dist.clear();

    }
    return 0;
}

