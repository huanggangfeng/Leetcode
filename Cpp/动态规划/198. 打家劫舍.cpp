// https://leetcode-cn.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return nums[0] > nums[1]? nums[0]:nums[1];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        int ret = 0;
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        return dp[nums.size() -1];
    }
};

// 空间复杂度优化， 只需要保存当前位置之前的2个值即可
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return nums[0] > nums[1]? nums[0]:nums[1];
        int dp[nums.size()];
        int prev1 = nums[0];
        int prev2 = nums[0] > nums[1]? nums[0]: nums[1];
        int ret = 0;
        for (int i = 2; i < nums.size(); i++) {
            // dp[i] = max(dp[i-2] + nums[i], dp[i-1])
            ret = max(prev1 + nums[i], prev2);
            prev1 = prev2;
            prev2 = ret;
        }
        return ret;
    }
};