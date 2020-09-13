// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/

// 不限制买卖次数，所以同一天既可以买也可以卖，
 // 贪心法其实最快
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <=1)
            return 0;
        int profit;
        for (int i = 1; i < prices.size(); i++) {
            int tmp = prices[i] - prices[i-1];
            if (tmp > 0)
                profit += tmp;
        }
        return profit;
    }
};


// dp 参考下面链接
// 状态 dp[i][j] 定义如下

// 第一维 i 表示索引为 i 的那一天（具有前缀性质，即考虑了之前天数的收益）能获得的最大利润；
// 第二维 j 表示索引为 i 的那一天是持有股票，还是持有现金。这里 0 表示持有现金（cash），1 表示持有股票（stock）。

// 作者：liweiwei1419
// 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/tan-xin-suan-fa-by-liweiwei1419-2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <=1)
            return 0;
        int profit;
        int dp[len][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < len; i++) {
            // 这两行调换顺序也是可以的
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[len - 1][0];

    }
};

// 进一步优化

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <=1)
            return 0;

        int cash = 0;
        int stock = -prices[0];
        for (int i = 1; i < len; i++) {
            cash = max(cash, stock + prices[i]);
            stock = max(stock, cash - prices[i]);
        }
        return cash;
    }
};