/*
Fast Exponentiation Method to Calculate a^b quickly.
Both iterative and recursive versions shown below.
*/
#include <iostream>
using namespace std;

int power_recursive(int a, int b)
{
    if (b == 0)
        return 1;
    int tmp = power_recursive(a, b / 2);
    int result = tmp * tmp;
    if (b % 2 == 1)
        result *= a;
    return result;
}

int power_iterative(int a, int b)
{
    int result{1};
    while (b > 0)
    {
        if (b % 2 == 1)
            result *= a; //%M
        a *= a;          //%M
        b /= 2;
    }
    return result;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << power_iterative(a, b) << "\n";
}