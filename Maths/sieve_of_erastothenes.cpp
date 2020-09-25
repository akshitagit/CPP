/*
Implementation of Sieve of Erastothenes - The most efficient way to find prime numbers upto n or check if a number is prime or not :)

*/

#include<bits/stdc++.h>
using namespace std;

vector<int> sieve(){
    int n=1e6+1;
    vector<int> counts(n,1);
    for(int i=2;i*i<=n;i++){
        
        if(counts[i]==1){
            for(int j=i*i;j*j<=n;j+=i){
                counts[j]=0;
            }
        }
    }
    return(counts);
}

int main(){
    cout<<"Enter the numer to check if its prime or not: ";
    int num;
    cin>>num;
    if(sieve()[num]) cout<<"Yes";
    else cout<<"No";
    return(0);
}
