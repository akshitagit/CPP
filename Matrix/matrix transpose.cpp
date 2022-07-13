#include <iostream>
using namespace std;

int main()
{
	int i,j,row,column,matrix[20][20],transpose[20][20];
		cout<<"enter first number as row and second number as column: ";
		cin>>row>>column;
		
		for(i=1;i<=row;i++)
		{
			for(j=1;j<=column;j++)
			{
				cout<<"enter the number: ";
				cin>>matrix[i][j];
				
			}
		}
		cout<<"your matrix is: \n";
		for(i=1;i<=row;i++)
		{
			for(j=1;j<=column;j++)
			{
				
				cout<<" "<<matrix[i][j];
			}
			cout<<endl;
		}
		for(i=1;i<=row;i++)
		{
			for(j=1;j<=column;j++)
			{
				transpose[j][i]=matrix[i][j];
			}
			cout<<"\n";
		}
		cout<<"your matrix transpose is: \n";
		for(i=1;i<=row;i++)
		{
			for(j=1;j<=column;j++)
			{
				
				cout<<" "<<transpose[i][j];
			}
			cout<<endl;
		}
}
