#include<bits/stdc++.h> 
using namespace std;

void printDivisors(long long int n){
	for(long long int i = 1; i * i <= n; ++i){
		if(n % i == 0){
			if(n / i == i) cout << i << ' ';
			else cout << i << ' ' << n / i << ' ';
		}
	}
	cout << endl;
}

int main(void){
	long long int n;
	while(1){
		cout << "enter the value of n [n<= 0 to stop]: ";
		cin >> n; 
		if(n <= 0) break;
		else printDivisors(n);
	}
}
