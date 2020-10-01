#include <iostream>
#include<algorithm>
using namespace std;

class Edge
{
    public:
    int src;
    int dest;
    int wt;
};

int find(int v, int *parent)
{
    if(parent[v]==v)
    {
        return parent[v];
    }
    return find(parent[v],parent);
}
bool compare(Edge e1, Edge e2)
{
    return (e1.wt<e2.wt);
}

void kruskal(Edge *node, int n, int e)
{
    sort(node,node+e,compare);
    Edge *output=new Edge[n-1];
    int *parent=new int[n];
    
    for(int i=0; i<n; i++)
        parent[i]=i;
        
    int count=0; 
    int i=0;
    while(count !=n-1)
    {
        Edge currentEdge=node[i];
        int src=find(currentEdge.src,parent);
        int dest=find(currentEdge.dest,parent);
        
        if(src !=dest){
        output[count]=currentEdge;
        count++;
        }
        i++;
    }
}

int main() {

	int n,e;
	cin>>n>>e;
		Edge *input=new Edge[e];
	for(int i=0; i<e; i++)
	{
	    cin>>input[i].src>>input[i].dest>>input[i].wt;
	}
	
	kruskal(input,n,e);
	
	
	for(int i=0; i<n-1; i++)
	{
	    if(input[i].src <input[i].dest)
	    {
	        cout<<input[i].src<<" "<<input[i].dest<<" "<<input[i].wt<<endl;
	    }
	    else
	    {
	         cout<<input[i].dest<<" "<<input[i].src<<" "<<input[i].wt<<endl;
	    }
	}
	return 0;
}
