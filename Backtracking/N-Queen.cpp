    #include<bits/stdc++.h>
    using namespace std;
    int ans=0;
    int dx[8]={+1,0,-1,-1,-1,0,+1,+1};
    int dy[8]={+1,+1,+1,0,-1,-1,-1,0};
    
    bool canplace(vector<vector<int>> board,int n,int c)
    {
        for(int i=0;i<n;i++)
            if(board[i][c]) //for that col check
                return false;
        
        return true;
    }
    bool issafe(vector<vector<int>> board,int n,int r,int c)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<8;j++)
            {
                int currrow=r+(dx[j]*i);
                int currcol=c+(dy[j]*i);
                
                if(currrow>=0 && currcol>=0 && currrow<n && currcol<n && board[currrow][currcol]==1)
                    return false;
            }
        }  
        return true;
    }
    bool issuccess(vector<vector<int>> board,int n,int c)
    {
        if(c>=n)
        {
        ans++;
        return true;
        }
            
        for(int i=0;i<n;i++)
        {
                if(canplace(board,n,c)==true && issafe(board,n,i,c)==true)
                {board[i][c]=1;
                
                issuccess(board,n,c+1);
                
                board[i][c]=0;
                }
        }
        return false;
    }
    int main()
    {
        int n;
        cin>>n;
        vector<vector<int>> board(n,vector<int>(n,0));
        issuccess(board,n,0); 
        cout<<ans<<endl;
        return 0;
    }