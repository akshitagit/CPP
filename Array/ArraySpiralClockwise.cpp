   /* 
      Question : To print a 2-Dimensional Array spirally clockwise 

      Sample Input :
        Enter the row and column :
        2 3

        4 5 6
        1 3 4
        
        Sample Output :
        4 5 6 4 3 1

   
      Variable Keys :
        k - starting row index  
        m - ending row index  
        l - starting column index  
        n - ending column index  
        i - iterator  
    */


#include <bits/stdc++.h> 
using namespace std; 

 
 
int main() 
{    
    int r,c;
    cout<<"Enter the row and column :"<<endl;
    cin>>r>>c;  // Taking the row and column as input 

    int a[r][c] ;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>a[i][j];
        }
    }
    int i, k = 0, l = 0; 
     int  m=r; 
     int n=c;
  
     while (k < m && l < n) { 
        
        for (i = l; i < n; ++i) {     //Print the first row from the remaining rows  
            cout << a[k][i] << " "; 
        } 
        k++; 
  
     
        for (i = k; i < m; ++i) {       // Print the last column from the remaining columns 
            cout << a[i][n - 1] << " "; 
        } 
        n--; 
  
      
        if (k < m) {          
            for (i = n - 1; i >= l; --i) {        // Prints the last row from the remaining rows  
                cout << a[m - 1][i] << " "; 
            } 
            m--; 
        } 
  
        /* Prints the first column from 
                   the remaining columns */
        if (l < n) { 
            for (i = m - 1; i >= k; --i) { 
                cout << a[i][l] << " "; 
            } 
            l++; 
        } 
    } 
    return 0; 
} 