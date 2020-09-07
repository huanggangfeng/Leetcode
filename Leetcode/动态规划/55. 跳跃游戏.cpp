// https://leetcode-cn.com/submissions/detail/100149831/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1)
            return true;
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 0; i < n; i++) {
            if (dp[i] != 0) {
                int max = i + nums[i];
                if (max > n - 1)
                    max = n - 1;;
                for (int j = i + 1; j <= max; j++) {
                    dp[j] = 1;
                }
            }
        }
        return dp[n - 1] == 1;
    }
};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1)
            return true;
        int n = nums.size();
        int max_distance = 0;
        for (int i = 0; i < n; i++) {
            // 最远距离大于等于当前距离，也就是暗示当前点肯定是可到达的
            if(max_distance >= i)
                max_distance = max(max_distance, i + nums[i]);
        }
        return max_distance >= n - 1;
    }
};