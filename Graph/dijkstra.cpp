
vector<vector<ll> > Graph::lazyDijkstra(int startingNode){
	visited.resize(numOfNodes+1,false);
	vector<ll> dist(numOfNodes+1,1e18+1);
	vector<ll> prev(numOfNodes+1,-1);
	priority_queue<pil,vector<pil>,comparePILByWeight> pq;

	pq.push({startingNode,0LL});
	dist[startingNode]=0LL;
	while(!pq.empty()){
		auto cur = pq.top(); pq.pop(); 
		int curNode = cur.first; ll wt = cur.second;
		
		if(dist[curNode]<wt) continue;
		visited[curNode]=true;

		for(int child:G[curNode]){
			if(visited[child]) continue;
			ll newDist = dist[curNode]+
			edgeW[{min(curNode,child),max(curNode,child)}];
			if(newDist<dist[child]){
				dist[child]= newDist;
				prev[child]= curNode;
				pq.push({child,newDist});
			}
		}
	}
	//for(int i=1;i<=numOfNodes;i++)
	//	cout<<i<<" "<<dist[i]<<"\n";
	return {dist,prev};
}