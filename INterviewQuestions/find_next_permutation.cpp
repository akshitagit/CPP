#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &A) {
    bool found=false;
    int index,n=A.size(),i,j;
    
    for(i=n-2;i>=0;i--){
        if(A[i]<A[i+1]){
            found=true;
            break;
        }
    }
    if(!found){
        sort(A.begin(),A.end());
        return A;
    }
    for(j=i+1;j<n;j++){
        if(A[j]>A[i])
        index=j;
    }
    
    swap(A[index],A[i]);
    
    sort(A.begin()+i+1,A.end());
    return A;
}

int main()
{
	int n;
	cin>>n;
	vector<int>A(n);
	for(int i=0;i<n;i++)
	cin>>A[i];
	
	vector<int>ans=nextPermutation(A);
	
	for(int i=0;i<n;i++)
	cout<<ans[i]<<" ";
	cout<<"\n";
	
	return 0;
}
