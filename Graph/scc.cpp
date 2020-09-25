
void Graph::traversalSCC(int cur, int src, stack<int> &st, vector<bool> &onStack,int &scc){
	onStack[cur]=true;
	st.push(cur);
	ids[cur]=lowLink[cur]=id++;

	for (int child:G[cur]){
		if(ids[child]==-1)
			traversalSCC(child,cur,st,onStack,scc);
		if(onStack[child])
			lowLink[cur]=min(lowLink[cur],lowLink[child]);		
	}
	if(lowLink[cur]==ids[cur]){
		int val=st.top(); st.pop();
		while(val!=cur){
			cout<<val<<" ";
			onStack[val]=false;
			lowLink[val]=ids[cur];
			val=st.top(); st.pop();
		}
		onStack[val]=false;
		cout<<val<<"\n";
		scc++;
	}
}

// For directed Graphs
int Graph::stronglyConnectedComponents(){
	ids.resize(numOfNodes+1,-1);
	lowLink.resize(numOfNodes+1);
	vector<bool> onStack(numOfNodes+1,false);
	stack<int> ele;
	int scc=0;

	for(int i=1;i<=numOfNodes;i++){
		if(ids[i]==-1) 
			traversalSCC(i,-1,ele,onStack,scc);
	}
	return scc;
}