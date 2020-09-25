
void Graph::traversalArt(int root,int cur,int src,int id,int &outEC,vector<bool> &isArt){
	if(src==root) outEC++;
	visited[cur]=true;
	lowLink[cur]=ids[cur]=id++;
	
	for(int child:G[cur]){
		if(src==child) continue;
		if(!visited[child]){
			traversalArt(root,child,cur,id,outEC,isArt);
			lowLink[cur]=min(lowLink[cur],lowLink[child]);
			if(ids[cur]<=lowLink[child])
				isArt[cur]=true;
		}
		else
			lowLink[cur] = min(lowLink[cur],ids[child]);
	}
}

vector<bool> Graph::findArticulationPoints(){

	vector<bool> isArt(numOfNodes+1,false);
	visited.resize(numOfNodes+1,false);
	lowLink.resize(numOfNodes+1);
	ids.resize(numOfNodes+1);
	int outEdgeCount;
	
	for(int i=1;i<=numOfNodes;i++){
		if(visited[i]) continue;
		outEdgeCount=0;
		traversalArt(i,i,-1,0,outEdgeCount,isArt);
		isArt[i] = (outEdgeCount>1);		
	}
	for(int node=1;node<=numOfNodes;node++)
		if(isArt[node]) cout<<" "<<node;
	cout<<"\n";
	return isArt;
}