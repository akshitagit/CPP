#include<bits/stdc++.h>
using namespace std;

int kthGrammar(int n, int k) {
	
	if(n==1&&k==1)
		return 0;
	
	int len = pow(2,n-1);
	
	if(k<=len/2)
	{
		return kthGrammar(n-1,k);
	}
	
	return !(kthGrammar(n-1,k-len/2));
        
}



int main()
{
	vector<int> v;
	
	cout<<kthGrammar(2,2)<<endl;
	
}