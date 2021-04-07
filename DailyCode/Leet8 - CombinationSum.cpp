// Combination Sum

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int fun(vector<int> v){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<endl;
	}
}

int main(){
	std::vector<int> v;
	int input;
	for(int i=0;i<v.size();i++){
		cin>>input;
		v.push_back(input);
	}
	fun(v);


}