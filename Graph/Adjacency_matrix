#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	int n;
	cout<<"Enter the number of vertices"<<endl;
	cin >> n;
	int A[n][n];
	int opt;
	for(int i =0;i<n;i++){
		static int v1 = 65;
		static int v2 = 65;
		for(int j =0;j<n;j++){
			
			printf("Is %c and %c are connected?",v1,v2);
			cout <<"Yes ---> 1\nNo--->0"<<endl;
			cin >> opt;
			if(opt==1) A[i][j]=1;
			else A[i][j]=0;
			v2++;
		
		}
		v2 = 65;
		v1++;
	}
	for(int i =65;i<65+n;i++) {
		for(int j =65;j<65+n;j++){
		if(A[i-65][j-65]==1) {
		printf("\n%c and %c are connected",i,j);}
			}
}
}
