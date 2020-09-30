/*
Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.
Input Format :

9 Lines where ith line contains ith row elements separated by space

Output Format :

 true or false

Sample Input :

9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6

Sample Output :

true

*/
#include<iostream>
using namespace std;

bool cellCheck(int board[][9],int a,int b,int key){
    
    for(int i=a;i<a+3;i++){
        for(int j=b;j<b+3;j++){
            if(board[i][j]==key)
                return false;
        }
    }
    return true;
}

bool rowCheck(int board[][9],int r,int key){
    
    for(int i=0;i<9;i++){
        if(board[r][i]==key)
            return false;
    }
    return true;
}

bool colCheck(int board[][9],int c,int key){
    
    for(int i=0;i<9;i++){
        if(board[i][c]==key)
            return false;
    }
    return true;
}

void printboard(int board[][9]){
    //Print Board
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    
    cout<<"= = = = = = = = = "<<endl;
}
bool solve(int board[][9],int i,int j){
    if(i==8 && j==8){
        if(board[8][8]==0){
            for(int t=1;t<=9;t++){
                if(rowCheck(board,8,t) && colCheck(board,8,t) && cellCheck(board,6,6,t))
                    return true;
            }
            return false;
        }
        else
            return true;
    }    
    bool ans;
    if(board[i][j]==0){
        for(int t=1;t<=9;t++){
                if(rowCheck(board,i,t) && colCheck(board,j,t) && cellCheck(board,3*(i/3),3*(j/3),t)){
                    board[i][j]=t;
                    //cout<<"i: "<<i<<" j: "<<j<<endl;
                    //printboard(board);
                    if(j<8)
                        ans=solve(board,i,j+1);
                    if(j==8)
                        ans=solve(board,i+1,0);
                }
            }
        if(board[i][j]==0)
            return false;
        if(ans==false)
            board[i][j]=0;
    }
    else{
        if(j<8)
            ans=solve(board,i,j+1);
        if(j==8)
            ans=solve(board,i+1,0);
    }
    return ans;
    
}


bool sudokuSolver(int board[][9]){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Don't print output and return output as specified in the question
  */
    bool ans=solve(board,0,0);
    
    return ans;


}

int main(){

  int n = 9; 
  int board[9][9];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> board[i][j];
        }		
  }
  if(sudokuSolver(board)){
	cout << "true";	
  }else{
	cout << "false";	
  }
}
