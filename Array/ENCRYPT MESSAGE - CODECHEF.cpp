/*CH01*/



#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	string s;
	cin>>s;
	if(n%2 == 0){
		for(int i=0;i<=n;i=i+2){
			s[i] = s[i]^s[i+1];
			s[i+1] = s[i]^s[i+1];
			s[i] = s[i]^s[i+1];
		}
	}else{
		for(int i=0;i<n-1;i=i+2){
			s[i] = s[i]^s[i+1];
			s[i+1] = s[i]^s[i+1];
			s[i] = s[i]^s[i+1];
		}
	}
	for(int i = 0;i<s.size();i++){
		char a = s[i];
		a = a - 97;
		s[i] = 122-a;
	}
	cout<<s<<endl;
	}	
}
