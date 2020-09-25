
class Tree: public Graph{
	vector<int> depth;
	vector<vector<int> > dp;

public:

	void lcaUtil(int src,int par, int dpt);
	int lca(int node1, int node2, int root);	

};

#include "lca.cpp"
