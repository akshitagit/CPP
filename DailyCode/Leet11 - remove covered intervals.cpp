// Remove Covered Intervals


#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int remcovintrvals(vector<vector<int> > v;){
	for(int i=0;i<v.size();i++){
		for(int j=0;j<v.size();j++){
			if(v.at[i+1][j]<=v.at[j] && v.at[j+1]<=v.at[i+1][j+1]){
				v.Remove();
			}
		}
	}
}

int main(){
	std::vector<vector<int> > vec;
	int edge,n1,n2;
	cin>>edge;
	vec.resize(edge);
	for(int i=0;i<edge;i++){
		cin>>n1>>n2;
		vec[n1].push_back(n2);
	}

	for(const auto& a: vec){
		for(const auto& b: a){
			cout<<b;
		}
		cout<<",";
	}

	remcovintrvals(vec);
}