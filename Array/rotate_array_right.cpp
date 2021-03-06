#include<iostream>
using namespace std;
//rotating array to the right by k
void rotate_right_by_n(int a[], int n, int k)
{
  int temp;
  for(int i=0;i<k;i++)
  {
    temp = a[n-1];
    for(int j=n-2;j>=0;j--)
    {
      a[j+1] = a[j];
    }
    a[0] = temp;
  }
}

// print function
void print(int a[], int n)
{
  cout<<"Array: ";
  for(int i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }
  cout<<endl;
}

int main()
{
  int arr[8]={1,2,3,4,5,6,7,8};
  print(arr, 8);
  rotate_right_by_n(arr, 8, 3);
  print(arr, 8);
  return 0;
}
