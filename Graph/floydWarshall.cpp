
void Graph::propogateNegativeCycles(vector<vector<ll> > &dp, vector<vector<int> >&next){
	int V = numOfNodes;
	for(int k=1;k<=V;k++){
		for(int i=1;i<=V;i++){
			for(int j=1;j<=V;j++){
				if(dp[i][k]+dp[k][j]<dp[i][j]){
					dp[i][j] = -INF;
					next[i][j] = -1;
				}
			}
		}
	}
}

// O(V*V*V)
vector<vector<ll> > Graph::floydWarshall(){
	int V=numOfNodes;
	vector<vector<ll> > dp(V+1,vector<ll>(V+1,INF));
	vector<vector<int> > next(V+1,vector<int>(V+1,-1));

	for(int i=1;i<=V;i++)
		dp[i][i]=0LL;
	for(auto edge:edgeW){
		int from=edge.first.first, to=edge.first.second;
		ll wt = edge.second;
		dp[from][to] = wt;
		next[from][to] = to;
	}

	for(int k=1;k<=V;k++){
		for(int i=1;i<=V;i++){
			for(int j=1;j<=V;j++){
				if(dp[i][k]+dp[k][j]<dp[i][j]){
					dp[i][j] = dp[i][k]+dp[k][j];
					next[i][j] = next[i][k];
				}
			}
		}
	}

//	propogateNegativeCycles(dp,next);
	for(int i=1;i<=V;i++){
		for(int j=1;j<=V;j++){
			if(dp[i][j]<=-INF) cout<<"-INF ";
			else if(dp[i][j]>=INF) cout<<"NP ";
			else cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	return dp;
}