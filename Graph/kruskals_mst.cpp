#define vvi vector<vector<int>>
#define vi vector<int>
// function to sort graph edges by weight in ascending order
bool myC(vi a, vi b){
   return a[2]<b[2];
}
// find function to find the parent of a node
int find(vi& par,int i ){
   if(par[i]==i) return par[i];
   return find(par,par[i]);
}
// uni function to merge the disconnected nodes
/*the one who's rank is more is made parent
if ranks are same then one of them is made parent and its rank is increased by 1*/
void uni(vi& par,vi& rn, int x, int y){
   if(rn[x]>rn[y]){
       par[y] = x;
   }
   else if(rn[y]>rn[x]){
       par[x] = y;
   }
   else{
       par[x] = y;
       rn[x]++;
   }
}
// B vector denotes vector of (u,v,weight) of undirected graph
// A denotes no of vertices
int Solution::solve(int A, vector<vector<int> > &B) {
   sort(B.begin(),B.end(),myC);
   vi par(A+1), rn(A+1,0);
   for(int i = 0;i<A+1;i++) par[i] = i;
   int ans = 0;
   for(int i = 0;i<B.size();i++){
       int x1 = find(par,B[i][0]) , x2 = find(par,B[i][1]);
       if(x1!=x2){
           ans+=B[i][2];
           if(B[i][1]!=B[i][0])
           uni(par,rn, x1,x2);
       }
   }
   return ans;// ans is the total of distance to cover all nodes
}

