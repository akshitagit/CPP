#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


/**The algorithm makes use of Kadane's Algorithm for getting the maximum value from the subsequence by updating the maximum_so_far 
obtained at each step*/
int main()
{
    long long int n; //enter the size of the array
    cin>>n;
    long long int arr[n]; //declare the array
    for(int i=0;i<n;i++)
    cin>>arr[i];
    long long int maximum_so_far=arr[0];
    long long int current=arr[0];
    for(int i=1;i<n;i++)
    {
        current=max(arr[i],current+arr[i]);
        maximum_so_far=max(maximum_so_far,current);
    }
    cout<<"The maximum value of contiguous subsequence in the array is="<<maximum_so_far<<"\n";
    return 0;
}
