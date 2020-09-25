


bool Graph::hasEulerianPath(vector<int> &in, vector<int> &out){
	int inNodes=0, edNodes=0;
	for(int i=1;i<=numOfNodes;i++){
		out[i]=G[i].size();
		for(int child:G[i])
			in[child]++;
	}

	for(int i=1;i<=numOfNodes;i++){
		if(out[i]-in[i]>1 || in[i]-out[i]>1) return false;
		if(out[i]-in[i]==1) inNodes++;
		else if(in[i]-out[i]==1) edNodes++;
	}
	return ( (inNodes==0 && edNodes==0) || 
		(inNodes==1 && edNodes==1) );
}

int Graph::findStartingNode(vector<int> in, vector<int> out){
	int startingNode = 0;
	for(int i=1;i<=numOfNodes;i++){
		if(out[i]-in[i]==1) return i;
		if(out[i]) startingNode=i;
	}
	return startingNode;
}

int Graph::findEndingNode(vector<int> in, vector<int> out){
	int endingNode = 0;
	for(int i=1;i<=numOfNodes;i++){
		if(in[i]-out[i]==1) return i;
		if(in[i]) endingNode=i;
	}
	return endingNode;
}

void Graph::eulerianTraversal(int cur, vector<int> &path, vector<int> &order){
	//cout<<" "<<cur;
	order[cur]++;
	if(order[cur]>G[cur].size()) return;
	eulerianTraversal(G[cur][order[cur]-1], path, order);
	
	path.push_back(cur);
}

void Graph::eulerPath(){
	vector<int> path;
	vector<int> inDegree(numOfNodes+1,0);
	vector<int> outDegree(numOfNodes+1,0);
	vector<int> order(numOfNodes+1,0);

	bool isPath = hasEulerianPath(inDegree,outDegree);
	cout<<"\nisPath: "<<isPath<<"\n";

	if(!isPath){ cout<<"\nNo Eulerian Path!\n";return;}

	int st = findStartingNode(inDegree,outDegree);
	int ed = findEndingNode(inDegree,outDegree);
	cout<<"\nstartingNode: "<<st;
	eulerianTraversal(st, path, order);
	cout<<"\nendingNode: "<<ed;


	reverse(path.begin(),path.end());
	path.push_back(ed);

	//Make sure the graph is not disconnected	
	if(path.size() != numOfEdges+1){
		cout<<"\nGraph is disconnected!!!\n";
		return;
	}
	cout<<"\nPath is: ";
	for(int node:path) cout<<" "<<node;
}