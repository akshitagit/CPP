

// O(M*log(M))
vector<vector<int> > Graph::primsMST(){

	visited.resize(numOfNodes+1,false);
	priority_queue<piil,vector<piil>,comparePILByWeight> pq;
	vector<vector<int> > mst;
	ll minCost=0LL;

	mst.resize(numOfNodes+1,vector<int>());

	for(auto edge:edgeW)
		pq.push({{edge.first.first,edge.first.second},edge.second});
	
	int nodeCount=0;
	while(!pq.empty() && nodeCount!=numOfNodes){
		auto edge = pq.top(); pq.pop();
		int node1 = edge.first.first, node2=edge.first.second;
		if(visited[node1] && visited[node2]) continue;
		if(!visited[node1]){ visited[node1]=true; nodeCount++;}
		if(!visited[node2]){ visited[node2]=true; nodeCount++;}

		mst[node1].push_back(node2); mst[node2].push_back(node1);
		minCost += edge.second;
	}
	if(nodeCount<numOfNodes){ 
		cout<<"\nGraph is Disconnected!\n"; 
		return {{-1}};
	}
	cout<<"\nCost of MST is: "<<minCost;
	return mst;
}