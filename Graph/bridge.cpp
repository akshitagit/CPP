
void Graph::traversal(int cur, int par, int val,
	vector<pair<int,int> > &bridges){
	visited[cur] =  true;
	lowLink[cur] = ids[cur] = val++;

	for(int child:G[cur]){
		if(child==par) continue;
		if(!visited[child]){
			traversal(child,cur,val,bridges);
			lowLink[cur] = min(lowLink[child],lowLink[cur]);
			if(ids[cur] < lowLink[child])
				bridges.push_back({cur,child});			
		}
		else
			lowLink[cur] = min(lowLink[cur],ids[child]);
	}
}

vector<pair<int,int> > Graph::findBridges(){

	ids.resize(numOfNodes+1);
	lowLink.resize(numOfNodes+1);
	vector<pair<int,int> > bridges;
	visited.resize(numOfNodes+1,false);

	for(int node=1;node<=numOfNodes;node++){
		if(visited[node]) continue;
		traversal(node,-1,0,bridges);	
	}
	for(auto bridge:bridges){
		cout<<bridge.first<<" "<<bridge.second<<"\n";
	}
	return bridges;
}