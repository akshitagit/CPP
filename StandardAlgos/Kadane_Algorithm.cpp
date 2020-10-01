#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int> v, int n)
{
	int i, globalMax = INT_MIN, localMax = 0;
	for(i=0;i<n;i++){
		localMax += v[i];
		if(localMax > globalMax)
			globalMax = localMax;
		if(localMax < 0)
			localMax = 0;
	}
	return globalMax;
}

int main()
{
	vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
	cout<<maxSubArraySum(arr,8);
	
	return 0;
}
