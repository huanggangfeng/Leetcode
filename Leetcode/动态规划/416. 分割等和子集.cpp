// 这个问题可以转换为经典的0-1背包算法，从n件物品中选出价值等于总和一半的物品
// 0-1是从所有物品中选出满足背包容量的物品

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.empty())
            return true;
        int n = nums.size();
        if (n < 2)
            return false;

        int total_value = 0;
        int max_num = INT_MIN;
        for (auto num : nums) {
            total_value += num;
            max_num = max(max_num, num);
        }

        if (total_value % 2 != 0)
            return false;
        int target = total_value / 2;
        if (max_num > target)
            return false;

        // [i, j] 表示从0-i个物品中选出一些，让它的价值等于j
        vector<vector<bool>> dp(n+1, vector<bool>(target + 1, false));
        // 从任意多的物品中选出价值为0的物品，结果都是true
        for (int i = 0; i <= n; i++)
            dp[i][0] = true;

        for (int i = 1; i <= n; i++) {
            int num = nums[i - 1];
            for (int j = 1; j <= target; j++) {
                if (j >= num) {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - num];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][target];
    }
};

// 二维数组的滚动优化
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.empty())
            return true;
        int n = nums.size();
        if (n < 2)
            return false;

        int total_value = 0;
        int max_num = INT_MIN;
        for (auto num : nums) {
            total_value += num;
            max_num = max(max_num, num);
        }

        if (total_value % 2 != 0)
            return false;
        int target = total_value / 2;
        if (max_num > target)
            return false;

        // [i, j] 表示从0-i个物品中选出一些，让它的价值等于j
        // vector<vector<bool>> dp(n+1, vector<bool>(target + 1, false));
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        // 从任意多的物品中选出价值为0的物品，结果都是true
        // for (int i = 0; i <= n; i++)
        //     dp[i][0] = true;


        for (int i = 1; i <= n; i++) {
            int num = nums[i - 1];
            for (int j = target; j > 0; j--) {
                // 每一行都是在前一行的基础上的值，所以可以二维优化为一维数组，还有j的时候，上一层j-num的值，所以从右往左的遍历
                // if (j >= num) {
                //     dp[i][j] = dp[i - 1][j] || dp[i - 1][j - num];
                // } else {
                //     dp[i][j] = dp[i - 1][j];
                // }
                if (j >= num)
                    dp[j] = dp[j] || dp[j-num]; 
            }
        }

        return dp[target];
    }
};