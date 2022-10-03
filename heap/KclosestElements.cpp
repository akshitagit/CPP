#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-k-closest-elements/

//siddhartha v

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
  
  vector<int> ans(k);
  
  priority_queue<pair<int,int>> pq;  
  
  for (int i = 0; i < arr.size(); i++)
  {
  	pq.push({abs(arr[i]-x),arr[i]});
  	if(pq.size()>k){
  		pq.pop();
  	}
  }
  for(int i = k-1;i>=0;i--){
  	ans[i]=(pq.top().second);
  	pq.pop();
  }
  
  sort(ans.begin(), ans.end());
 
  return ans;       
}

int main()
{
	vector<int> v={1,2,3,4,5};
	vector<int> ans = findClosestElements(v,4,3);
	for(auto it:ans)
		cout<<it<<" ";
	cout<<endl;
	
}
