/*
You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Input Format :

Line 1 : Integer N

Output Format :

One Line for every board configuration. 
Every line will have N*N board elements printed row wise and are separated by space

Note : Don't print anything if there isn't any valid configuration.
Constraints :
1<=N<=10
Sample Input 1:

4

Sample Output 1 :

0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
*/

#include <vector>
#include<iostream>
using namespace std;


void printboard(vector<vector <int> > qboard){
    
    for(int i=0;i<qboard.size();i++){
        for(int j=0;j<qboard[i].size();j++){
            cout<<qboard[i][j]<<" ";
        }
    }
}

bool qdiagcheck(vector<vector <int> > qboard,int r,int c){
    
    int i=0;
    int n=qboard.size();
    while(r+i<n && c+i<n){
        if(qboard[r+i][c+i])
            return false;
        i++;
    }
    i=0;
    
    while(r-i>=0 && c+i<n){
        if(qboard[r-i][c+i])
            return false;
        i++;
    }
    i=0;
    
    while(r+i<n && c-i>=0){
        if(qboard[r+i][c-i])
            return false;
        i++;
    }
    i=0;
    
    while(r-i>=0 && c-i>=0){
        if(qboard[r-i][c-i])
            return false;
        i++;
    }
    
    return true;
}

bool qrccheck(vector<vector <int> > qboard,int r,int c){
    
    //Column-Check
    for(int i=0;i<qboard.size();i++){
        if(qboard[i][c])
            return false;
    }
    
    return true;   
}
void solve(vector <vector<int> >qboard,int n,int r){
    
    if(n==0){
        printboard(qboard);
        cout<<endl;
        return;
    }
    
    for(int i=0;i<qboard.size();i++){
        
        if(qdiagcheck(qboard,r,i) && qrccheck(qboard,r,i)){
            qboard[r][i]=1;
            solve(qboard,n-1,r+1);
        }
        qboard[r][i]=0;
    }
    return;
    
}

void placeNQueens(int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
    vector <vector<int> >qboard(n,vector<int>(n,0));
    solve(qboard,n,0);
    
}

int main(){

  int n; 
  cin >> n ;
  placeNQueens(n);

}

