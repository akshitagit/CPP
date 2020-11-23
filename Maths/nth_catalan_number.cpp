// C++ program for nth Catalan Number  in O(n) time
#include<iostream>
using namespace std;
 
// Returns value of Binomial Coefficient C(n, k)
unsigned long int binomialCoeff(unsigned int n, unsigned int k)
{
    unsigned long int res = 1;
 
    // Since nCk equals nCn-k
    if (k > n - k)
        k = n - k;
 
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}
 
// A Binomial coefficient based function to find nth catalan
unsigned long int catalan(unsigned int n)
{
    // Calculate value of 2nCn
    unsigned long int c = binomialCoeff(2*n, n);
 
    // return 2nCn/(n+1)
    return c/(n+1);
}
 
// Driver program to test above functions
int main()
{
	int num;
	//Enter nth number
	cin>>num;
	//Print the nth catalan number
    cout << catalan(num) <<"\n";
    return 0;
}
