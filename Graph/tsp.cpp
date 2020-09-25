
vector<vector<ll> > Graph::TSP(int S){
	int V=numOfNodes;
	vector<vector<int> > combinations(V+1,vector<int>());
	vector<vector<ll> > dp(V,vector<ll>((1<<V),INF));

	for(int i=1;i<=(1<<V);i++)
		combinations[__builtin_popcount(i)].push_back(i);

	//For V=2 case:
	for(int i=0;i<V;i++){
		if(i==S) continue;
		dp[i][(1<<i)|(1<<S)] = G[S][i];
	}

	//For V>2 case:
	ll minDist=INF;
	for(int bitsCount=3;bitsCount<=V;bitsCount++){
		for(int state:combinations[bitsCount]){
			// We are going to make this current state using edge last->next
			//Check if S is present in state
			if( ((1<<S)&state)==0 ) continue;
			minDist=INF;
			for(int next=0;next<V;next++){
				if(  ((1<<next)&state)==0 || next==S )
					continue;
				int tmpState = state^(1<<next);

				for(int last=0;last<V;last++){
					if(last==next ||  ((1<<last)&state)==0 || last==S) continue;
					ll newDist = dp[last][tmpState] + G[last][next];
					if(dp[next][state]>newDist) dp[next][state] = newDist;
				} 
				minDist=min(minDist, dp[next][state]);
			}
		}
	}
	//cout<<"Distance: "<<minDist;
	return dp;
}

vector<int> Graph::getPathTSP(int startingNode){
	
	vector<vector<ll> > dp = TSP(startingNode);
	ll dist=INF; int state=(1<<numOfNodes)-1, lastIndex=startingNode;
	vector<int> path(numOfNodes+1,-1);

	for(int i=0;i<numOfNodes;i++){
		if(i==startingNode) continue;
		if( dp[i][state]+G[i][startingNode] < dist){
			dist= dp[i][state]+G[i][startingNode];
		}
	}
	cout<<"\nShortest Distance: "<<dist<<"\n"; 	

	for(int i=numOfNodes-1;i>0;i--){
		int index=-1;
		for(int j=0;j<numOfNodes;j++){
			if(j==startingNode ||  ((1<<j)&state)==0) continue;
			if(index==-1) index=j;

			ll prevDist = dp[index][state]+G[index][lastIndex];
			ll newDist = dp[j][state]+G[j][lastIndex];
			if(newDist<prevDist) index=j;
		}

		path[i] = index;
		state = state^(1<<index);
		lastIndex = index;	
	}
	path[0]=path[numOfNodes]=startingNode;

	cout<<"\nPath: ";
	for(int node:path) cout<<node<<" ";
	
	return path;
}