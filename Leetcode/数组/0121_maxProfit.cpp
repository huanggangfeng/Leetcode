// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock

// Solution：纪录历史最低价，遍历数组，计算每一天卖出的利润

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int low = prices[0];
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            int tmp = prices[i] - low;
            if (tmp > profit)
                profit = tmp;
            if (prices[i] < low)
                low = prices[i];
        }
        return profit;
    }
};