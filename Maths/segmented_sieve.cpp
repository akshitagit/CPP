/*
Sometimes we need to find all prime numbers in a range [L,R] of small size (e.g. R−L+1≈1e7), 
where R can be very large (e.g. 1e12).
To solve such a problem, we can use the idea of the Segmented sieve.
 We pre-generate all prime numbers up to R−−√, and use those primes to mark all composite numbers in the segment [L,R].
While working on the last block it should not be forgotten that the last needed number n is not necessary located in the end of the block.
source-https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html 
*/

////////////////////////********IMPLEMENTATION(C++)*******************/////////////////////////

//This is a handy shortcut to include whole STL in c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int R, L;
    cin >> L >> R;
    vector<bool> isPrime(R - L + 1, true); //created a vector of size R-L and intitially setting all elements to true
    long long int lim = sqrt(R);
    for (long long int i = 2; i * i <= R; i++)
    {
        for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
        {
            isPrime[j - L] = false;
        }
    }
    if (L == 1)
    {
        isPrime[0] = false;
    }
    for (int i = 0; i <= R - L; i++)
    {
        if (isPrime[i])
        {
            cout << i + L << " ";
        }
    }
    /*
    Demo Output from the code
    if L=1 and R=10
    then output will be
    2 3 5 7 
    */
}