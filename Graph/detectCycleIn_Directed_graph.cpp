#include <bits/stdc++.h>
using namespace std;




/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/
bool check_cycle(vector<int> g[],int *visit,int *cycle,int k){
    cycle[k] = 1;
    visit[k] = 1;
    
    for(auto i = g[k].begin();i!=g[k].end();i++){
        if(cycle[*i] == 1){
            return true;
        }
        
        else if(cycle[*i] == 0)
            if(visit[*i] != 0 && check_cycle(g,visit,cycle,*i))return true;
        
    }
    cycle[k] = 0;
    return false;
}


bool isCyclic(int V, vector<int> adj[])
{
    int visited[V] = {0};
    int cycleCheck[V] = {0};
    for(int i=0;i<V;i++){
        if(visited[i] == 0){
            if(check_cycle(adj,visited,cycleCheck,i))
                return true;
        }    
    }
    return false;
    
}




int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}  