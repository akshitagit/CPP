#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int lexorder(string s){
	int pos = 0;
	int l = s.length();
	int count = 0;
	int i,j;
	for(i=0;i<l;i++){
		for(j=0;j<i;j++){
			if(s.at(i) == s.at(j)){
				break;
			}
		}
		if(j == i){
			s.at(pos++) = s.at(i);
		}
	}
	cout<<s;
}

int main(){
	string s;
	cin>>s;
	lexorder(s);
}