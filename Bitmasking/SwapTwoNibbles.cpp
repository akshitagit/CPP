#include <iostream>
using namespace std;
int main()
{
    int swapNibbles(int n);
    int n, result;
    cout << "Enter a number: ";
    cin >> n;
    result = swapNibbles(n);
    cout << result;

    return 0;
}

int swapNibbles(int n)
{
    return (((n & 0x0F) << 4) | ((n & 0xF0) >> 4));
}