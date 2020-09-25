#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int> > &A) {
    int n=A[0].size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            int temp=A[i][j];
            A[i][j]=A[n-j-1][n-i-1];
            A[n-j-1][n-i-1]=temp;
        }
    }
    int top=0,bottom=n-1;
    while(top<bottom){
        for(int j=0;j<n;j++){
            int temp=A[top][j];
            A[top][j]=A[bottom][j];
            A[bottom][j]=temp;
        }
        top++;
        bottom--;
    }
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> A(n,vector<int>(n));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>A[i][j];
		}
	}
	rotate(A);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<A[i][j]<<" ";
		}
		cout<<"\n";
	}
}
