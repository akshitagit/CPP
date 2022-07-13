
#include<iostream.h>
using namespace std;

void Spiralprint( int a[][1000] , int m , int n){
    int StartRow = 0;
    int StartCol = 0;
    int endRow = m-1;
    int endCol = n-1;

    while(StartRow<=endRow and StartCol<=endCol){
        //first Row
        for(int i = StartCol; i<=endCol; i++){
            
            //Because row will fix column only will change
            cout<< a[StartRow][i]<<",";
        }
        StartRow++;

        for(int i= StartRow; i<=endRow; i++){
            //Here row will change And column will be fixed
            cout<<a[i][endCol]<<",";
        }
        endCol--;

        //Bottom Row;
        if(endRow > StartRow){  //For modifying
            for(int i=endCol; i>=StartCol; i--){
                cout<< a[endRow][i]<<",";
            }
            endRow--;
        }

        //Start Col
        if(endCol > StartCol){   //For modify
        for(int i=endRow; i>=StartRow; i--){
            cout<< a[i][StartCol]<<",";
        }
        StartCol++;
        }
    }
}
int main(){
    int a[1000][1000] = {0};
    int m,n;
    cin>>m>>n;
    int val = 1;
    for(int row =0; row<= m-1; row++){
        for(int col=0; col<=n-1; col++){
            a[row][col] = val;
            val = val+1;
            cout<<a[row][col]<<" ";
        }
        cout<<endl;
    }
    Spiralprint(a , m , n);
    return 0;
}

Example:-    
1.>
Input:-                          Output:-
4  4                          1  2  3  4  8  12  16  15  14  13  9  5  6  7  11  10
1  2  3  4
5  6  7  8
9 10 11 12
13 14 15 16

2.>
Input:-                     Output:-
5 3                         1  2  3  6  9  12  15  14  13  10  7  4  5  8  11                 
1  2  3
4  5  6
7  8  9
10 11 12
13 14 15

3.>
INput:-                    Output:-
3 5                      1  2  3  4  5  10  15  14  13  12  11  6  7  8  9
1  2  3  4  5
6  7  8  9  10
11 12 13 14 15

Note:- In example 2 and example 3  we will get wrong Output but here due to modification(endRow>StartRow , endCol>StartCol)
we are getting right Output......