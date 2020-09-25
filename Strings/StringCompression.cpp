#include<bits/stdc++.h>
using namespace std;

int main(){
	string str;
	string res = "";
	int index = 0;
	cin>>str;                          //Input string

	cout<<"Compressed String :"<<endl;

	for(int i=0; i<str.length(); i++) {
	    int count = 1;
	    while(i<str.length() && str[i]==str[i+1]) {
	        count++;
	        i++;
	    }
        res += str[i];
        res += count+'0';
	}

	cout<<res<<endl;
	return 0;
}
