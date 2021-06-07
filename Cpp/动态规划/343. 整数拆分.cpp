// https://leetcode-cn.com/problems/integer-break/

// 和剪绳子解法一模一样

class Solution {
public:
    int integerBreak(int n) {
        if (n < 2)
            return 0;
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
         vector<int> dp(n + 1, 0);
         for (int i = 2; i <= n; i++) {
             for (int j = 1; j < i; j++) {
                int tmp =  max(j * (i - j), j * dp[i - j]);
                dp[i] = max(dp[i], tmp);
             }
         }
         return dp[n];
    }
};