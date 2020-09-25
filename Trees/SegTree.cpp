#include <iostream>
#include <bits/stdc++.h>
#define SIZE 100002
#define ll long long

using namespace std;

class SegmentTree{
public:
	vector<ll> segTree( 1<<(log(SIZE) + 1), -1);


	void createSegTree(int start, int end, int A[], int low, int high, int index){
		if(start==end){
			segTree[index] = A[start];
			return;
		}

		int mid = (start+end)/2;
		ll res1 = createSegTree(start,mid,A,low,high,index*2+1);
		ll res2 = createSegTree(mid+1,end,A,low,high,index*2+2);
		return max(res1,res2);
	}

	void updateSegTree(int start,int end,int X,ll Y,int index){
		if(start==end){
			segTree[start]+=Y;
			return;
		}

		int mid=(start+end)/2;
		if(X<=mid) updateSegTree(start,mid,X,Y,index*2+1);
		else updateSegTree(mid+1,end,X,Y,index*2+2);
	}

	ll runQuery(int start, int end, int low, int high, int index){
		if(low>end || high<start) return 0LL;
		if(start>=low && end<=high) return segTree[index];

		int mid=(start+end)/2;
		ll val1 = runQuery(start,mid,low,high,index*2+1);
		ll val2 = runQuery(mid+1,end,low,high,index*2+2);
		return max(val1,val2);
	}
};

int main(){

}