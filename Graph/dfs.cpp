//Time Complexity - O(N)
void Graph::dfsUtil(int node,int src){
	cout<<" "<<node;          //output node value in the order of dfs
	visited[node]=true;         //mark node as visited

	for(int child:G[node]){		//loop through all nodes connected to currect node 
		if(child==src) continue;		
		dfsUtil(child,node);
	}
}

//Considering Disconnected Graph as well
int Graph::dfs(int node){
	int connectedComponents = 0;
	visited.resize(numOfNodes+1,false);
	
	//Considering Disconnected Graph as well
	for(int i=1;i<=numOfNodes;i++){
		if(visited[i]) continue ;//if visited then continue
		else
		{connectedComponents++;	
		dfsUtil(i,-1);           
		}
	}
	
	//returns the number of connected components
	return connectedComponents;
}
