/* 
Sample Input : 
3
11 2 4
4 5 6
10 8 -12
Sample Output : 15  
*/


#include <bits/stdc++.h>
using namespace std;

/* Code by Mayank Pathak */

int main()
{
    int n,s=0,c=0,d=0;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        cin>a[i][j];
        }
     }  
   for(int i=0;i<n;i++)
    {
        c+=a[i][i];
    }
   for(int i=0;i<n;i++)
    {
        d+=a[i][n-1-i];
    }
    s=abs(c-d);
    cout<<s;
    return 0;
}
 
