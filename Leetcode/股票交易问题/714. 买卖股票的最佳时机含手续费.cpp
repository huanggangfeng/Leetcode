class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len = prices.size();
        if (len <= 1)
            return 0;
        int ret = 0;
        // 第i天有2种状态, 空仓或者满仓
        int dp[len][2];
        dp[0][0] = 0; // 第一天空仓
        dp[0][1] = -prices[0] - fee; // 第一天满仓
        for (int i = 1; i < len; i++) {
            // 第i天空仓有2可能： 1:
            // 1. 前一天已经空仓, dp[i-1][0]
            // 2. 前一天还持有股票， 今天卖出的， dp[i-1][1] + prices[i] - fee;
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee);
        }

        return dp[len-1][0];
    }
};