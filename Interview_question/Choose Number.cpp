#include<iostream>
#include<climits>

using namespace std;
string Number(int arr[], int n) {
    if(n<3)
        return "NO";
    int max1, max2, min;
    max1=max2=INT_MIN;
    min=INT_MAX;
    for(int i=0; i<n; i++) {
        if(arr[i]<min)
            min=arr[i];
        if(arr[i]>max2) {
            max2=arr[i];
            if(max2>max1) {
                max2=max1;
                max1=arr[i];
            }
        }
    }
    if(max1+max2 >= min)
        return "YES";
    return "NO";
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<Number(arr, n);
    return 0;
}
