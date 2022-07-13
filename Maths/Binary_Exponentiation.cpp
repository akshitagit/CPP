//Problem: Binary Exponentiation better approach
#include<bits/stdc++.h>
using namespace std;

int power(long long a,long b)
{
	int result=1;
	while(b>0){  //Return 1
		if(b%2==1) result *=a;  //Odd number
		a*=a; 
		b/=2; //Even Number
	}
	return result;
}
int main()
{
	long long a,b;
	cin>>a>>b;
	cout<<power(a,b);
	return 0;
}


//TimeCoplexity : O(logn)
