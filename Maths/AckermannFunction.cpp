#include <iostream>
using namespace std;

int ackermannFunction(int m, int n)
{
  if (m == 0)
  {
    return n + 1;
  }
  else if ((m > 0) && (n == 0))
  {
    return ackermannFunction(m - 1, 1);
  }
  else if ((m > 0) && (n > 0))
  {
    return ackermannFunction(m - 1, ackermannFunction(m, n - 1));
  }
}
int main()
{
  int m, n;
  cout << "Enter two non negative integers:" << endl;
  cin >> m >> n;
  int result = ackermannFunction(m, n);
  cout << result << endl;
  return 0;
}