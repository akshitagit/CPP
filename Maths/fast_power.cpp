/*

CPP program to compute a^b in O(logn) time.

*/

#include <bits/stdc++.h>
using namespace std;

//Power Function
template <typename T>
double fast_power(T a, T b)
{
    if (b < 0)
    {
        return (1.0 / fast_power(a, -b));
    }
    double result = 1;
    while (b)
    {
        if (b & 1)
            result = result * a;
        a = a * a;
        b = b >> 1;
    }
    return result;
}
// Main Function
int main()
{
    int a, b;
    cout << "Enter Two Numbers (a,b) : ";
    cin >> a >> b;
    cout << fixed << fast_power(a, b) << endl;
    return 0;
}
