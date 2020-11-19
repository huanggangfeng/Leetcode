// https://leetcode-cn.com/submissions/detail/100149831/


class Solution { // 动态规划, 时间复杂度 = O(N^2)
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        // 动态规划, dp[i] 表示从数组下标 0 出发, 是否可以到达数组下标 i;
        // dp[i] = 0, 无法到达; dp[i] = 1, 可以到达; 
        vector<int> dp(N, 0);
        dp[0] = 1;

        // 状态转移方程, 对于 dp[i], 逆序遍历 [0,i-1] 的每个位置
        // 执行次数 = 1 + 2 + ... + (N-1) = N(N-1)/2, 所以, 时间复杂度 = O(N^2)
        for (int i = 1; i < N; i++) {
            for (int j = i-1; j >= 0; j--) {
                if ((dp[j] == 1) && (nums[j] >= i - j)) {
                    dp[i] = 1; 
                    break;
                }
            }
        }

        // 返回结果
        return dp[N-1] == 1;
    }
};


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
            else
                return false;
        }
        return max_distance >= n - 1;
    }
};