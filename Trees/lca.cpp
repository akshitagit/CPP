
void Tree::lcaUtil(int cur, int src,int dep){
	dp[cur][0]=src;
	depth[cur]=dep;
	
	for(int i=1;i<=LOGSIZE && dp[cur][i-1]!=-1;i++)
		dp[cur][i]=dp[ dp[cur][i-1] ][i-1];
	for(int child:G[cur]){
		if(child==src) continue;
		lcaUtil(child,cur,dep+1);
	}
}

int Tree::lca(int u, int v, int root){
	dp.resize(SIZE,vector<int>(LOGSIZE+1,-1));
	depth.resize(numOfNodes+1,0);
	lcaUtil(root,-1,1);
	
		if(depth[u]<depth[v]) swap(u,v);
		for(int i=LOGSIZE;i>=0;--i)
			if(dp[u][i]!=-1 && depth[dp[u][i]]>=depth[v]) u=dp[u][i];
		if(u==v) return u;
		for(int i=LOGSIZE;i>=0;--i)
			if(dp[u][i]!=dp[v][i])	u=dp[u][i], v=dp[v][i];
		
	return dp[u][0];
}
