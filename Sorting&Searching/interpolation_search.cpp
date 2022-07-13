#include<bits/stdc++.h>
using namespace std;

int interpolation(int a[],int low,int high,int k){
  int mid;
  while(low<=high){
    mid = low + (((double)(high - low)/(a[high] - a[low]))*(k - a[low])); 
    if (k == a[mid])
      return mid;
    if (k < a[mid])
      return interpolation(a,low,mid-1,k);
    else
      return interpolation(a,mid+1,high,k);
  }
  return -1;
}

int main(){
int n,key;
  cout << "Enter size of the array:"<<endl;
  cin >> n;
  cout << "Enter the array elements:"<<endl;
  int *arr = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "Enter the key to be searched:"<<endl;
  cin >> key;
  int res = interpolation(arr,0,n-1,key);
  if (res != -1)
    cout << key << " found at index " << res << endl;
  else
    cout << key << " not found in the array" << endl;
  return 0;
}


/*
Sample Input/Output:
1. Enter size of the array:
5
Enter the array elements:
12 23 31 40 57 61
Enter the key to be searched:
23
Output: 23 found at index 1

2. Enter size of the array:
5
Enter the array elements:
12 23 31 40 57 61
Enter the key to be searched:
31
Output: 31 not found in the array
*/
