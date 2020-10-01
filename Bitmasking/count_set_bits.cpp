
#include <iostream>
using namespace std;

int main()
{int t,n,c,i=0;
	
	cin>>t;
	int a[t];
	
	while(i<t)
	{	
		c=0;
		cin>>n;
		while(n!=0)
		{
			if(n%2==1)
				c++;
			n=n/2;
		}
		a[i]=c;
	i++;
	}
	
	for(i=0;i<t;i++)
	{
		cout<<a[i]<<endl;
	}
		
	return 0;
}
