#include<iostream>
using namespace std;


int main(){
    int n,t,z;
    cin>>t;
    for(z=0;z<t;z++){
	cin>>n;

	int a[100000];///CHANGE. array size was small.
	//Input
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	//Kadane's Algorithm
	int cs=0,ms=0;
	for(int i=0;i<n;i++){
		cs += a[i];
		cs = cs<0?0:cs;
		ms = max(ms,cs);

	}
	cout<<ms<<endl;
    }
	return 0;
}