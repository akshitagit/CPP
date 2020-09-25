/*
    Basic Eucledian algorithm for GCD of two numbers
*/
#include <bits/stdc++.h>
using namespace std;

int basicGCD(int a, int b) {
    if (a == 0)
        return b;
    return basicGCD(b % a, a);
}

int main() {
    int a, b;
    cin>>a>>b;
    int gcd = basicGCD(a, b);
    cout << gcd << endl;
    return 0;
}
