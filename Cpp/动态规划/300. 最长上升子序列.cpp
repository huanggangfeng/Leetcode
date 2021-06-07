// https://leetcode-cn.com/problems/longest-increasing-subsequence/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return n;

        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] +1);
                }
            }
        }

        int ret = dp[0];
        for (int i = 1; i < n; i++) {
            if (dp[i] > ret)
                ret = dp[i];
        }

        return ret;
    }
};