#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Graph
{
    private: 
        int v;
        vector<int> *adj;
    public:
        Graph(int vertices)
        {
            this->v = vertices;
            this->adj = new vector<int>[this->v];
        }
        void addEdge(int x, int y)
        {
            this->adj[x].push_back(y);
            this->adj[y].push_back(x);
        }
        void printGraph()
        {
            for(int i = 0; i < this->v; i++)
            {
                cout << i << "->";
                for( int u : this->adj[i])
                {
                    cout << u << " ";
                }
                cout << endl;
            }
        }
        void DFSRec(int s, bool visited[])
        {
            visited[s] = true;
            cout << s << " ";
            for( int u : this->adj[s] )
            {
                if(visited[u] == false)
                {
                    DFSRec(u, visited);
                }
            }
        }

        void DFS(int s)
        {
            bool visited[this->v];
            for(int i = 0; i < this->v; i++)
            {
                visited[i] = false;
            }
            for(int i = 0; i < this->v; i++)
            {
                if(visited[i] == false)
                {
                    DFSRec(i, visited);
                }
            }
        }

        bool cycleRec(int s, bool visited[], int parent)
        {
            visited[s] = true;
            for(int u: this->adj[s])
            {
                if(visited[u] == false)
                {
                    if(cycleRec(u, visited, s) == true)
                    {
                        return true;
                    }
                }
                else if(u != parent)
                {
                    return true;
                }
            }
            return false;
        }
        bool cycle(int s)
        {
            bool visited[this->v];
            for(int i = 0; i < this->v; i++)
            {
                visited[i] = false;
            }
            for(int j = 0; j < this->v; j++)
            {
                if(visited[j] == false)
                {
                    if(cycleRec(j, visited, -1) == true)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        void BFSDis(int s, bool visited[])
        {
            queue<int> q;
            q.push(s);
            visited[s] = true;
            while (q.empty() == false)
            {
                int u = q.front();
                q.pop();
                cout << u << " ";
                for(int U: this->adj[u])
                {
                    if(visited[U] == false)
                    {
                        visited[U] = true;
                        q.push(U);
                    }
                }
            }
            
        }
        void BFS(int s)
        {
            bool visited[this->v];
            for(int i = 0; i < this->v; i++)
            {
                visited[i] = false;
            }
            for(int i = 0; i < this->v; i++)
            {
                if(visited[i] == false)
                {
                    BFSDis(i, visited);
                }
            }
        }
};
int main(int argc, char *argv[])
{
    Graph g(10);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.printGraph();
    g.DFS(0);
    g.cycle(0) ? cout << "cyclic " : cout << "Non cyclic ";
    cout << endl << "BFS :";
    g.BFS(0);
    return 0;
}