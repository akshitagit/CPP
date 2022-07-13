//infinite grid formed by replication of initial n*m grid
//All co-ordinates are 0-indexed
//Answer rectangular queries (x1,y1,x2,y2)

int n, m;
ll F(int x,int y){
    if(x < 0 || y < 0) return 0;
    
    //12
    //34
    int r = x / n; int c = y / m;
    int X = x % n; int Y = y % m;

    //Case 1 : r * c Full blocks)
    if(r && c){
        //Add contribution of g(0,0,n-1,m-1)
        //in range row[0,r-1] and col[0,c-1]
    }

    //Case 2 : c partial (row-wise) blocks
    if(c){
        //Add contribution of g(0,0,X,m-1)
        //in range col[0,c-1]
    }

    //Case 3 : r partial (col-wise) blocks
    if(r){
        //Add contribution of g(0,0,n-1,Y)
        //in range row[0,r-1]
    }

    //Case 4 : only partial (both row and col-wise) block(r,c)
    //Add contribution of g(0,0,X,Y) for block(r,c)
}

ll Solve(int x1,int y1,int x2,int y2){
    return F(x2,y2) - F(x1-1,y2) - F(x2,y1-1) + F(x1-1,y1-1);
}
