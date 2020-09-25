
vector<ll> Graph::bellmanFord(int startingNode){
	vector<ll> dist(numOfNodes+1,INF);
	int V=numOfNodes;
	dist[startingNode]=0;

	for(int i=0;i<V-1;i++){
		for(auto edge:edgeW){
			int from=edge.first.first, to=edge.first.second;
			ll wt=edge.second;
			if(dist[to]>dist[from]+wt)
				dist[to]= dist[from]+wt;
		}
	}

	for(int i=0;i<V-1;i++){
		for(auto edge:edgeW){
			int from=edge.first.first, to=edge.first.second;
			ll wt=edge.second;
			if(dist[to]>dist[from]+wt){
				dist[to]=-1*INF;
			}
		}
	}
	/*
	for(int node=1;node<=numOfNodes;node++){
		cout<<"\n"<<node<<": ";
		if(dist[node]<=-1*INF)
			cout<<"-INF ";
		else cout<<dist[node];
	}
	cout<<"\n";
	*/
	return dist;
}