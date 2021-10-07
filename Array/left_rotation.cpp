// C++ program to implement left rotation in an array.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int k;
    cin >> n >> k;
    int a[n];
    for(int i = 0;i < n;i++)
        cin >> a[i];
    reverse(a , a + k - 1);
    reverse(a + k , a + n);
    reverse(a , a + n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
  return 0;
}
