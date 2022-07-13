/* DP solution for house robber problem leetcode challenge */

int rob(vector<int>& nums) {
        int len = nums.size();
		if (!len) return 0;
		if (len == 1) return nums[0];
		if (len == 2) return max(nums[0], nums[1]);
		vector<int> dp{nums[0], max(nums[0],nums[1])};
		for (int i = 2; i < len; i++)
			dp.push_back(max(dp[i - 1], nums[i] + dp[i - 2]));
		return dp[dp.size() - 1];
    }