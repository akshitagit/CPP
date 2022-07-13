/*
    floyd warshall algo for min distance between all edges;
    negative edges and negative cycle allowed
    O(V^3)
*/

#include<iostream>
using namespace std;

class Graph{

    public:
        int ** floyd_warshal_algo(int ** adj , int V){

            int ** dp = new int *[V];

            for(int i = 0 ; i < V ; ++i){
                dp[i] = new int [V];
                for(int j = 0 ; j < V ; ++j){
                    dp[i][j] = adj[i][j];
                }
            }

            for(int k = 0 ; k < V ; ++k){

                for(int i = 0 ; i < V ; ++i){

                    for(int j = 0 ; j < V ; ++j){

                        if(dp[i][k] != -1 && dp[k][j] != -1 && (dp[i][j] == -1 || dp[i][j] > dp[i][k] + dp[k][j])){
                            dp[i][j] = dp[i][k] + dp[k][j];
                        }

                    }

                }

            }

            return dp;

        }

};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V;
    cin>>V;
    int ** adj = new int * [V];

    for(int i = 0 ; i < V ; ++i){
        adj[i] = new int [V];
        for(int j = 0 ; j < V ; ++j){
            cin>>adj[i][j];
        }
    }

    
    Graph g1;

    int ** dp = g1.floyd_warshal_algo(adj , V);

    cout<<"Min distance between every nodes:\n";

    for(int i = 0 ; i < V ; ++i){
        for(int j = 0 ; j < V ; ++j){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }

}