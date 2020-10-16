// Link to the problem : https://leetcode.com/problems/running-sum-of-1d-array/
// Problem Name : Running Sum of 1d Array
// Solution Method : Array Traversal

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0) {
                nums[i] += nums[i-1];
            }
        }
        return nums;
    }
};
