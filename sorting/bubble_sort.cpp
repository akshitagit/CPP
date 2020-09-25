//Bubble-sort in C++

#include<bits/stdc++.h>

using namespace std;

//passing array by reference inorder to sort original array
int bubble_sort(vector<int> &arr)
{
    //number of elements in the arr
    int n = arr.size();

    //bubble sort algorithm
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j+1] < arr[j])
                swap(arr[j],arr[j+1]);
        }
    }
}

int main()
{
    //arr is the array to be sorted
    vector<int> arr{1, 9, 4, 6, 8, 3, 2, 7};

    //calling function bubble_sort
    bubble_sort(arr);

    //printing the sorted array
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    
    return 0;
}