#include<bits/stdc++.h>
using namespace std;

/*  Merge Sort uses the concept of divide and conquer. The concept breaks the problem into sub problems untill they become small enough to be solved directly. */


void merge(vector<int> &v, vector<int> left, int leftCount, vector<int> right, int rightCount){
  /*
     This function is responsible for the combining the two divided left and right array into a sorted vector v.
  */
	int i = 0, j = 0, k = 0;
	while(i < leftCount && j < rightCount){
		if(left[i] < right[j])
			v[k++] = left[i++];
		else
			v[k++] = right[j++];
	}
	while(i < leftCount)
		v[k++] = left[i++];
	while(j < rightCount)
		v[k++] = right[j++];
}

void mergeSort(vector<int> &v, int n){
 /*
    This function is responsible for breaking the problem into subproblems.
    This uses recursion to divide the array into left and right array and we stop or return when our left and right array size becomes 1.
    Finally as the recursion backtracks we call merge above that combines these left and right arrays into one sorted array.
    Thus, doing so gives us our sorted array.
 */	
	if(n < 2) return;
	int mid = n/2;
	vector<int> left(mid), right(n-mid);
	for(int i = 0; i < mid; i++)
		left[i] = v[i];
	for(int i = mid ; i < (int)v.size(); i++)
		right[i - mid] = v[i];
	mergeSort(left, mid);
	mergeSort(right, n - mid);
	merge(v, left, mid, right, n-mid);
}

int main(){
	int n;
	cin>>n;                          //Input size
	vector<int> v(n);                  
	for(auto &it : v) cin>>it;       //Input an array to be sorted
	mergeSort(v, n);
	cout<<"Sorted Array :"<<endl;
	for(int i : v)
		cout<<i<<" ";
	cout<<endl;	
	return 0;
}
