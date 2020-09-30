#include<bits/stdc++.h> 
using namespace std; 

#define MAX 500 

int multiply(int x, int ans[], int size){ 
	int carry = 0;  
	for (int i=0; i<size; i++){ 
		int prod = ans[i] * x + carry; 
		ans[i] = prod % 10; 
		carry = prod/10;	 
	} 
	while (carry){ 
		ans[size] = carry%10; 
		carry = carry/10; 
		size++; 
	} 
	return size; 
} 


void factorial(int n){ 
	int ans[MAX]; 
	ans[0] = 1; 
	int size = 1; 
	for (int x=2; x<=n; x++) 
		size = multiply(x, ans, size); 
	cout << "Factorial of given number is: \n"; 
	for (int i=size-1; i>=0; i--) 
		cout << ans[i]; 
} 
int main() { 
    int n;
    cin>>n;
	factorial(n); 
	return 0; 
} 

/*
Sample I/P-
100  
Sample O/P-
Factorial of given number is:                                                                                                 
933262154439441526816992388562667004907159682643816214685929638952175999932299156089414639761565182862536979208272237582511852
10916864000000000000000000000000 
*/
