#include<bits/stdc++.h>
using namespace std;
int main(){

	string s, t;
	cin>>s>>t;
	
        int m = t.size(); //size of text
	int n = s.size(); //size of string to searched
        s += '#';
	int pi[n + 1];
	pi[0] = 0;
        for(int i = 1; i < n + 1; i++){ //caculating prefix function for the string s 
		int j = pi[i-1];
		while(j > 0 && s[i] != s[j])
			j = pi[j-1];
		if(s[i] == s[j])
			j++;
		pi[i] = j;
	}

	cout<<"Prefix function for string s:"<<endl;
	for(int i = 0; i < n + 1; i++)
		cout<<pi[i]<<" ";

	cout<<endl;
       
	int count = 0, prev = 0;
	vector<int> occur;
	for(int i = 0; i < m; i++){
		int l = prev;
		while(l > 0 && t[i] != s[l])
			l = pi[l - 1];
		if(t[i] == s[l])
			++l;
		prev = l;
		if(l == n){
			count++;
			occur.push_back(i);
		}
	}
	cout<<"Occurences of string s in text t is/are : "<<count<<endl;
	cout<<"Starting indexes of the occurences : ";
	for(int x : occur){
               cout<<(x - (n-1))<<" ";
	}
	cout<<endl;
	
	return 0;
}
