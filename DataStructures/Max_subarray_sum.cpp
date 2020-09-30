#include<bits/stdc++.h>

using namespace std;

long maxSubArraySum(long a[], long size)
{
    long max_so_far = INT_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

int main()
{
     int t;
     cin>>t;

     while(t--)
     {
          long n;
          cin>>n;

          long a[n],i,j;
          for(i=0;i<n;i++)
               cin>>a[i];
         cout<<maxSubArraySum(a,n)<<"\n";
     }
}
