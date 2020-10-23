bool isSafe(int m[MAX][MAX],int row,int col,int n, bool vis[][MAX]){
    if(row==-1 || row==n ||col==-1 || col==n || m[row][col]==0||vis[row][col])
    return false;
  return true;
}

void path(int m[MAX][MAX], int n,vector<string>&res,int row,int col,bool vis[][MAX],string&s){
    if(row==-1 || row==n ||col==-1 || col==n || m[row][col]==0||vis[row][col])
    return ;
    if(row==n-1 && col== n-1){
        res.push_back(s);
        return ;
    }
    vis[row][col]=true;
    if(isSafe(m,row+1,col,n,vis)){
        s.push_back('D');
        path(m,n,res,row+1,col,vis,s);
        s.pop_back();
    }
    if(isSafe(m,row,col-1,n,vis)){
        s.push_back('L');
        path(m,n,res,row,col-1,vis,s);
        s.pop_back();
    }
    if(isSafe(m,row,col+1,n,vis)){
        s.push_back('R');
        path(m,n,res,row,col+1,vis,s);
        s.pop_back();
    }
    if(isSafe(m,row-1,col,n,vis)){
        s.push_back('U');
        path(m,n,res,row-1,col,vis,s);
        s.pop_back();
    }
    vis[row][col]=false;
}
vector<string> printPath(int m[MAX][MAX], int n) {
    vector<string>res;
    string paths;
    bool vis[n][MAX]; 
    memset(vis, false, sizeof(vis));
    path(m,n,res,0,0,vis,paths);
    return res;
}
