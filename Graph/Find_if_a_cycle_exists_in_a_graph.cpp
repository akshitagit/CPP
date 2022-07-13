#include<bits/stdc++.h>
using namespace std;

// Problem - Consider a directed or undirected graph without loops and multiple edges.
//           We have to check whether it is acyclic or not.

// nodes -> Total number of nodes that exists in graph
// edges -> Total number of edges that exists in graph
int nodes, edges;

// adj -> Graph represented in form of adjacency list
vector<vector<int>> adj;

// color -> vector which stores state of Graph
// color[u] == 0 -> Node u is unvisited
// color[u] == 1 -> Node u has been visited but is being processed right now
// color[u] == 2 -> Node u has been visited and processed
vector<int> color;

// Function to initialize adjacency list(Graph) and color vector
void Initialize() {
	adj.resize(nodes+1);
	color.resize(nodes+1, 0);
}

// Function to add edge from node u to node v
void AddEdge(int u, int v) {
	adj[u].push_back(v);
}

// DFS function which acts as helper function to Check_Cycle() in finding cycle
bool DFS(int u, int p) {
	color[u] = 1; // Mark node as visited and processing
	
	// Go through all connected nodes from node u
	for(int v : adj[u]) {
		if(v == p) // We can't go back to parent node p of node u from node v (v != p)
			continue;
		if(color[v] == 1) // Cycle found as that node v is still being processed
			return true;
		else if(color[v] == 0) // If node v is unvisited then process that
			return DFS(v, u); // In this case node v is processed and node u becomes parent of v
	}
	color[u] = 2; // Mark node as visited and processed
	return false; // If no cycle formed then return false
}

// Function to check if a cycle exists in a graph
bool Check_Cycle() {
	for(int u = 1; u <= nodes; u++) {
		// If node is unvisited then process
		if(color[u] == 0) {
			if(Check_Cycle(u, -1))
				return true;
		}
	}
	return false;
}

int main() {

	cin>>nodes>>edges;

	Initialize();

	for(int e = 1; e <= edges; e++) {
		int u, v;
		cin>>u>>v;
		AddEdge(u, v);
		AddEdge(v, u);
		// For directed graph, comment out last AddEdge line.
		// For undirected graph, both AddEdge lines are there.
	}

	if(Check_Cycle())
		cout<<"A cycle has been found in given graph."<<endl;
	else 
		cout<<"No cycle has been found in given graph."<<endl;
}

// Time Complexity - O(nodes + edges)
// Space Complexity - O(nodes)