#include<iostream>
using namespace std;
//testing weather the number is palindrome or not
void palindrome_test(int n)
{
  int n_copy, rem, n_rev = 0;
  n_copy = n;
  while(n_copy!=0)
  {
    rem = n_copy%10;
    n_rev = n_rev*10 + rem;
    n_copy = n_copy/10;
  }
  if(n_rev == n)
  {
    cout<<"Number "<<n<<" is a Palindrome."<<endl;
  }
  else
  {
    cout<<"Number "<<n<<" is not a Palindrome."<<endl;
  }
}
int main()
{
  int n;
  cout<<"Enter No.: ";
  cin>>n;
  palindrome_test(n);
  return 0;
}
