#include<bits/stdc++.h>
using namespace std;

/********************************************************
PROBLEM STATEMENT
    Given a set of coins and a target value, 
    find the number of distinct ordered ways to make that sum 
    assuming you have infinite supply of the given coins.

    Since the answer can get very large 
    output answer modulo 10^9 + 7

	In this program 'n' is the number of coins and 
	'k' is the target value.

BASIC IDEA
    At each step just keep the answers upto that particular
    instance of sum you have and work your way upto
    the required sum. Basically, solve the smaller
    sub-problems and arrive at the answer at the end.
*********************************************************/
 
const int mod = 1e9 + 7;
 
int main(){
	
	int n, k;
	scanf("%d %d", &n, &k);

	vector <int> coins(n), values(k+1, 0);

	for(int i = 0; i < n; i++){
		cin >> coins[i];
	}

	values[0] = 1;

	for(int i : coins){

		for(int j  = 1; j <= k; j++){

			if(j-i>=0){

				values[j] += values[j-i];
				values[j] %= mod;

			}
		}
	}
	cout << values[k];
}