#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int low, int high)
{
  for (int i = low, j = high; i < j; i++, j--)
  {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}

void leftRotate(int arr[], int r, int n)
{
  reverse(arr, 0, r - 1);

  reverse(arr, r, n - 1);

  reverse(arr, 0, n - 1);
}

int main()
{
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  int r = 3;
  leftRotate(a, r, n);

  return 0;
}