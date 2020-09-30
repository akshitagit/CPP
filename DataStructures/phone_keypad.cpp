#include<iostream>
using namespace std;
string table[]= { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void prints(char *input,char *out,int i,int j)
{
	if(input[i]=='\0')
	{
		out[j]='\0';
		cout<<out<<endl;
		return;
	}
    int digit=input[i]-'0';
	for(int k=0;table[digit][k];k++) 
	{ out[j]=table[digit][k];
		prints(input,out,i+1,j+1);
	}
}
int main() {
	char input[100];
	char out[100];
	cin>>input;
	prints(input,out,0,0);
	return 0;
}