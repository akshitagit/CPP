/*
	Extended Euclid's Algorithm for finding GCD of 2 elements
*/

#include <bits/stdc++.h>
using namespace std;

long long extendedGCD(long long a, long long b, long long &x, long long &y){ 
	if (a < b) {
		long long t = a;
		a = b;
		b = t;
	}
	if (b==0) {
		x = 0;
		y = 1;
		return a;
	}
	long long x1, y1;
	long long gcd = extendedGCD(b, a%b, x1, y1);
	x = y1 - (b/a) * x1;
	y = x1;
	return gcd;
}

int main() {
	long long a = 120;
	long long b = 118;
	long long x, y;
	long long g = extendedGCD(a, b, x, y);
	cout << g << endl;
}