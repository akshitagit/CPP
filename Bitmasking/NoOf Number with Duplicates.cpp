/*
Given a number n, find number of numbers that are greater than n using the same set of digits as n. n might have duplicate digits.
Input Format :

Integer n

Output Format :

Count of greater numbers

Sample Input :

122

Sample Output :

2

 */

#include <bits/stdc++.h>
using namespace std;



long NON(deque<long> &digarr,vector <long> &freq,vector <long> &fact,int n,int start){
    if(n==0 || n==1)
        return 0;
    
    long ans=0;
    long denom=1;
    for(int i=1;i<=9;i++){
        denom*=fact[freq[i]];
    }
    for(int i=digarr[start]+1;i<=9;i++){
        
        ans+=(fact[n-1]*freq[i])/denom;
    }
    
    freq[digarr[start]]--;
    ans+=NON(digarr,freq,fact,n-1,start+1);
    return ans;
}

long numberOfNumbersWithDuplicates(long num){
	// Write your code here
    
    deque <long> digarr;
    vector <long> freq(10);
    vector <long> fact;
    
    fact.push_back(1); //0! and 1!=1
    fact.push_back(1);
    while(num!=0){
        long d=num%10;
        
        int i=fact.size();
        freq[d]++;
        fact.push_back(fact[i-1]*i);
        digarr.push_front(d);
        
        num/=10;
    }
    long ans=NON(digarr,freq,fact,digarr.size(),0);
    
    return ans;
    

}


int main() {
    long n;
    cin >> n;
    cout << numberOfNumbersWithDuplicates(n) << endl;
}