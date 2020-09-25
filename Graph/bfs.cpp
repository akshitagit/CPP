
vector<int> Graph::bfs(int node){
	vector<int> prev(numOfNodes+1,-1);
	visited.resize(numOfNodes+1,false);

	queue<int> q;
	q.push(node);
	visited[node]=true;

	while(!q.empty()){
		node = q.front(); q.pop();
		for(int child:G[node]){
			if(!visited[child]){
				q.push(child);
				visited[child]=true;
				prev[child]=node;
			}
		}
	}
	return prev;
}

//To get the path from StartingNode to lastNode
vector<int> Graph::reconstructPathFromBFS(
	vector<int> prev, int startingNode, int endingNode){
	
	vector<int> path; //To store the path

	int ind=endingNode;
	path.push_back(endingNode); 
	while(prev[ind]!=-1){
		path.push_back(prev[ind]);
		ind = prev[ind];
	}
	reverse(path.begin(), path.end());
	if(path[0]==startingNode) return path;
	else return {-1};
}
