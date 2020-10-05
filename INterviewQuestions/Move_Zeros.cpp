//stable_partition is a function template present in algorithm header file of c++ STL
//Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
#include <bits/stdc++.h>
using namespace std;   
    
int main() 
{ 
    vector<int> v{ 6, 9, 0, 1, 2, 7, 5, 8, 0 }; 
    stable_partition(begin(nums),end(nums),[](int i){return i;});
    for (int n : v) { 
        cout << n << ' '; 
    } 
    cout << '\n';
    return 0;
} 
