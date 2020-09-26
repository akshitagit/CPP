 /*
-----

Question :

 Take N (number of rows), print the following pattern (for N = 4).

                   1 
                 2 3 2
               3 4 5 4 3
             4 5 6 7 6 5 4
 Input Format

Constraints

0 < N < 10

-----
*/

#include<bits/stdc++.h>
using namespace std;
 

void solve()
{
int n; 
cin>>n;    //Taking the number if rows "n" as input 

int num=0; //Initiliaing the variable which will keep track of the numbers to be printed.
 
 for (int i = 0; i < n; ++i)
 {
 	 for(int j=0;j<n-i ;j++)   //This for loop prints the leading whitespaces in the current row.
 	 {
 			cout<<"  ";
 	 }
 	for(int j=n-i;j<=n+i;j++)  //This for loop prints the numbers in the current row.
 	{
 		if(j>n)
 		{
 			cout<<  --num<<" "    ;
 		}
 		else 
         cout<< ++num <<" "  ;
 	}
 
 	 cout<<endl;
 }
 
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	 
	 solve();
		 
	 

	return 0;
}
