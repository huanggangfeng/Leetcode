// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/tu-jie-zhuang-tai-zhuan-yi-by-kkkchan/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        // f[i][0]: 空仓可以买
        // f[i][1]: 空仓不可买
        // f[i][2]: 持有股票
        int dp[n][3];
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = -prices[0];
        for (int i = 1; i < n; ++i) {
            // 今天空仓： 2可能， 前一个状态是空仓可以买，或者空仓不可买
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            // 今天空仓不可买：前一个状态肯定是持有股票
            dp[i][1] = dp[i - 1][2] + prices[i];
            // 今天持有股票： 前一个状态就持有，或者前一个状态是空仓可以买
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] - prices[i]);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};