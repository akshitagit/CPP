/*
You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed. All houses at this
place are arranged in a circle. 
That means the first house is the neighbor of the last one. 
Meanwhile, adjacent houses have a security system connected, 
and it will automatically contact the police if two adjacent 
houses were broken into on the same night.

Given a list of non-negative integers nums representing the amount
of money of each house, return the maximum amount of money you can
rob tonight without alerting the police.
*/


// Similar problem to the House Robber,
// but here is one more constraint compare to that
// i.e. the first and the last house are also adjacent.

// Solution:
// Apply the house robber algorithm two times,
// one time without the last house,
// second time without the firat house,
// return maximum answer from the above both output.


#include<bits/stdc++.h>

using namespace std;

int rob(vector<int>& nums) {
    if(nums.size()==0)
        return 0;
    if(nums.size()==1)
        return nums[0];

        
    if(nums.size()==2)
        return max(nums[0],nums[1]);
    
    int n=nums.size();
    
    // Ignore Last House.
    vector<int> dp(n-1,0);
    dp[0]=nums[0];
    dp[1]=max(nums[0],nums[1]);

    for(int i=2; i<n-1; i++) {
        dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
    }

    //Ingonre First House.
    vector<int> dp1(n-1,0);
    dp1[0]=nums[1];
    dp1[1]=max(nums[1],nums[2]);
    
    for(int i=3; i<n; i++) {
        dp1[i-1]=max(dp1[i-2],dp1[i-3]+nums[i]);
    }

    //return maximum from both.   
    return max(dp[n-2],dp1[n-2]);
}

int main() {
    vector<int> v{2,3,2};
    
    cout << rob(v);
}