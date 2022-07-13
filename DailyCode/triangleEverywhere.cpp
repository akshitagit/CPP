#include<iostream>
using namespace std;

int main(void) {
	long long int a,b,c;
	cin>>a>>b>>c;
	
	if(a+b>c and b+c>a and c+a>b){
	    if(a==b and b==c){
	    cout<<"1"<<endl;
	    }
	    else if(a==b or a==c){
	       cout<<"2"<<endl;
    	}
    	else if(a!=b and a!=c){
	        cout<<"3"<<endl;
	    }    
	}
	else{
	    cout<<"-1"<<endl;
	}
	return 0;
}

