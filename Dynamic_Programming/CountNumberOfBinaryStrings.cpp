// Given a positive integer N, count all possible distinct binary strings of length N such that there are no consecutive 1’s.

#include <bits/stdc++.h>
using namespace std;
int countStr(int n)
{
    int a[n], b[n];
    a[0] = 1, b[0] = 1;
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i - 1] + b[i - 1];
        b[i] = a[i - 1];
    }
    return a[n - 1] + b[n - 1];
}
int main()
{
    int n;
    cin >> n;
    cout << countStr(n) << endl;
    return 0;
}

/*
The user is required to add the lenght of the string
Input: 5
Output : 13

Input : 10
Output : 144

*/