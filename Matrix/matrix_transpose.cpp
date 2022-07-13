/*  This c++ program transposes a NxM matrix 
   Input givens are number of row, number of columns and matrix itself.
   After transposing prints the transposed matrix. 
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int m, n;

    cin >> m >> n; 
    // m is no. of rows  and n is no. of columns

    vector< vector <int> > matrix( m , vector<int> (n));

    //a transpose of a M x N matrix contains N rows and N columns
    vector< vector <int> > transposed_matrix( n , vector<int> (m)); 

    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cin >> matrix[i][j];    //Input
        }
    }
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            transposed_matrix[i][j] = matrix[j][i];   //transposing a matrix
        }
    }
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cout << transposed_matrix[i][j] << "\t";  //finally, printing the transposed matrix
        }
        cout << "\n";
    }
    return 0;
}