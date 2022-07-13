#include <iostream>
#include <climits>
using namespace std;

int main() 
{
    
    int n, i, currentsum=0, maxsum=INT_MIN;
    cin >> n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(i=0;i<n;i++)
    {
        currentsum=currentsum+a[i];
        if(currentsum<0)
        {
            currentsum=0;
        }
        maxsum=max(currentsum,maxsum);
    }
    cout << maxsum << "\n";
    
}