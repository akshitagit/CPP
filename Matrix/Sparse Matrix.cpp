#include <iostream>
using namespace std;
int main() {
	int n,m,i,j,k,key;
	cout<<"Enter the number of rows and column of matrix:"<<endl;
	cin>>n>>m;
	int b[n*m][3];//it takes element of matrix directly into the sparse matrix
	k=0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			cin>>key;//key variable is used for taking matrix variable
			if(key!=0){
				b[k][0]=i;
				b[k][1]=j;
				b[k][2]=key;
				k++;
			}
		}
	}
	cout<<"Sparse matrix is :"<<endl;
  cout<<"Row"<<"\t"<<"Column"<<"\t"<<"Element"<<endl;
	for(i=0;i<k;i++){
		for(j=0;j<3;j++){
			cout<<b[i][j]<<"\t";
		}
		cout<<endl;
	}
}
