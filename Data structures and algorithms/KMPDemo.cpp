#include<iostream>
using namespace std;

void KMP(string t, string p)
{
	int n=t.length();
	int m=p.length();
	int j;

	int res[m+1];

	for(int i=0; i<m+1; i++)
		res[i]=0;

	for(int i=1; i<m; i++)
	{
		j=res[i+1];

		while(j>0 && p[i]!=p[j])
			j=res[j];

		if(j>0 ||p[i]==p[j])
			res[i+1]=j+1;
	}
	for(int i=0, j=0; i<n; i++)
	{
		if(t[i]==p[j])
		{
			if(++j==m)
			{
				cout<<i-j+1;			
			}

		}		
		else if(j>0)
		{
			j=res[j];
			i--;
		}
	}
}
int main()
{
	string txt="ccadd";
	string patt="ddbcc";

	KMP(txt,patt);
	return 0;
}

