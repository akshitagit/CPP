/*
Given an array nums with n objects colored red, white, or blue, 
sort them in-place so that objects of the same color are adjacent,
with the colors in the order red, white, and blue.

Here, we will use the integers 0, 1, and 2 to represent the color 
red, white, and blue respectively.

Follow up:

1. Could you solve this problem without using the library's sort function?
2. Could you come up with a one-pass algorithm using only O(1) constant space?
*/

// Solution (Dutch National Flag Algorithm)
// Initialize three pointer (l=0,r=n-1,ptr=0)
// n is the size of the array
// ptr stands for holding current index while traversing 
// run loop till ptr<=r
// if(arr[ptr]==0)  swap(arr[l],arr[ptr]); l++; ptr++;
// else if(arr[ptr]==1) ptr++;
// else swap(arr[ptr],arr[r]); r--;

#include<bits/stdc++.h>

using namespace std;

void sortColors(vector<int>& nums) {
    int l=0,r=nums.size()-1,ptr=0;
    while(ptr<=r) {
        if(nums[ptr]==0) {
            swap(nums[l],nums[ptr]);
            l++;
            ptr++;
        }
        else if(nums[ptr]==2) {
            swap(nums[r],nums[ptr]);
            r--;
        }
        else
            ptr++;
    }
    return;
}

int main() {

    vector<int> v{0,2,1,1,0,2,2,1,0,0,1,1,0,2};
    
    sortColors(v,v.size());

    cout << "Output: "; 
    for(int i=0; i<v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}