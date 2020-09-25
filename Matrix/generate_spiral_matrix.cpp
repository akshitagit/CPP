#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > generateSpiralMatrix(int n)
 {
    int num=1,top=0,bottom=n-1,left=0,right=n-1;
    vector<vector<int>> A(n,vector<int>(n));
    bool horizontal =true;

    while(num<=(n*n))
    {
        if(horizontal)
        {
            for(int j=left;j<=right;j++)
            {
                A[top][j]=num;
                num++;
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
                A[i][right]=num;
                num++;
            }
            right--;
            horizontal=false;
        }
        else{
            for(int j=right;j>=left;j--)
            {
                A[bottom][j]=num;
                num++;
            }
            bottom--;
            for(int i=bottom;i>=top;i--)
            {
                A[i][left]=num;
                num++;
            }
            left++;
            horizontal=true;
        }
    }
    return A;
}

int main(){
	int n;
	cin>>n;
	
	vector<vector<int>> ans_matrix=generateSpiralMatrix(n);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<ans_matrix[i][j]<<" ";
		}
		cout<<"\n";
	}
}


