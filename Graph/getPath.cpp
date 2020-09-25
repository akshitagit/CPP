
vector<int> Graph::getPath(vector<vector<ll> > dist,
	int startingNode, int endingNode){	
	vector<int> path;
	while(endingNode!=-1){
		//cout<<endingNode<<"\n";
		path.push_back(endingNode);
		endingNode = dist[1][endingNode];		
	}	
	reverse(path.begin(),path.end());
	if(path[0]!=startingNode) return {-1};
	else return path;
}