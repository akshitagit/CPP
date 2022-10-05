#include<bits/stdc++.h>
using namespace std;

//gfg
//dlru

// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

//siddhartha v 

void solve(int n,vector<vector<int>> grid,int x,int y,vector<string> &ans,string path,vector<vector<int>> & checker){
	
	
	if(x==n-1&&y==n-1){
		ans.push_back(path);
		return;
	}
	
	
	if(x+1<n&&y<n&&checker[x+1][y]==0&&grid[x+1][y]==1){
		checker[x+1][y] = 1;
		path.push_back('D');
		solve(n,grid,x+1,y,ans,path,checker);
		path.pop_back();	
		checker[x+1][y] = 0;
		
	}
	if(x<n&&y-1>=0&&checker[x][y-1]==0&&grid[x][y-1]==1){
		checker[x][y-1]=1;
		path.push_back('L');
		solve(n,grid,x,y-1,ans,path,checker);
		path.pop_back();
		checker[x][y-1]=0;
		
	}if(x<n&&y+1<n&&checker[x][y+1]==0&&grid[x][y+1]==1){
		checker[x][y+1]=1;
		path.push_back('R');
		solve(n,grid,x,y+1,ans,path,checker);
		path.pop_back();
		checker[x][y+1]=0;
	}
	if(x-1>=0&&y<n&&checker[x-1][y]==0&&grid[x-1][y]==1){
		checker[x-1][y]=1;
		path.push_back('U');
		solve(n,grid,x-1,y,ans,path,checker);
		checker[x-1][y]=0;
	}
	
	
}

vector<string> ratInAMaze(int n,vector<vector<int>> grid){
	
	vector<string> ans;
	string path;
		
	//visited vector/array
	
	vector<vector<int>> checker;	
	vector<int> temp;
	for(int j=0;j<n;j++){
			temp.push_back(0);
		}
	for(int i=0;i<n;i++){
		
		checker.push_back(temp);
		
	}
	
	if(grid[0][0] == 0)
		return ans;
	
	checker[0][0] = 1;
	
	solve(n,grid,0,0,ans,path, checker);
	for(string s : ans)
		cout<<s<<endl;
	
	return ans;
	
	
}


int main()
{
	int n = 2;
	// vector<vector<int>> grid = {
	// 	{1,0,0,0},
	// 	{1,1,0,1},
	// 	{1,1,0,0},
	// 	{0,1,1,1}
	// };
	vector<vector<int>> grid = {
		{1,1},
		{1,1}
	};
	vector<int> v;
	ratInAMaze(n,grid);
}
