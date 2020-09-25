#include <iostream>
using namespace std;

int main() {
        int n, i, j;
        cout<<"Enter a number: "<<endl;
        cin>>n;
        
        for(i=0; i<=n; i++){
            for(j=0; j<i;j++){
                cout<<" ";
                if(j>=1)
                cout<<" ";
            }
            for(j=n-i;j>=0;j--){
                cout<<j<<" ";
            }
            for(j=1;j<=n-i;j++){
                cout<<j<<" ";
            }
            cout<<"\n";
        }
        for(i=n-1; i>=0; i--){
            for(j=0; j<i;j++){
                cout<<" ";
                if(j>=1)
                cout<<" ";
            }
            for(j=n-i;j>=0;j--){
                cout<<j<<" ";
            }
            for(j=1;j<=n-i;j++){
                cout<<j<<" ";
            }
            cout<<"\n";
        
}
	return 0;
}
