#include <iostream>
using namespace std;

int main() {
    long long int t;
    long long int n;
    int rem = 0;
    cin>>t;
    while(t-->0){
        cin>>n;
        while(n>0){
            rem = rem*10 + n%10;
            n = n/10;
        }
        cout<<rem<<endl;
        rem = 0;
        
    }
	return 0;
}
