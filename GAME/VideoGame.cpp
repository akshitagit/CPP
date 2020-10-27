
#include<iostream>
#include<algorithm>
using namespace std;

/*string removeSpaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    return str;
}*/

int main()
{
	long long int n,h,j=0,k=0;
	int a[100000],b[100000];
	string str;
	cin>>n>>h;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin.ignore();
	getline(cin, str);
	//str = removeSpaces(str);
	int x=str.length();
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='1')
		{
			if(j>=1)
			j--;
		}
		else
		if(str[i]=='2')
		{
			if(j<n-1)
			j++;

		}
		else
		if(str[i]=='3')
		{
			if(k==0&&a[j]>0)
			{
				a[j]--;
				k=1;
			}
		}
		else
		if(str[i]=='4')
		{
			if(k==1&&a[j]<h)
			{
				a[j]++;
				k=0;
			}
		}
		else
		if(str[i]=='0')
		{
			break;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
