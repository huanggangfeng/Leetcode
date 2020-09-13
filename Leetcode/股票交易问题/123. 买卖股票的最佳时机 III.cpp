// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/

// 参考
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/solution/wu-chong-shi-xian-xiang-xi-tu-jie-123mai-mai-gu-pi/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int len = prices.size();
        // dp[i][0] 从开始到现在啥都没干
        // dp[i][1] 从开始到现在只买入过一次
        // dp[i][2] 从开始到现在卖出过一次
        // dp[i][3] 从开始到现在只买入过2次
        // dp[i][4] 从开始到现在卖出过2次
        int dp[len][5];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;
        dp[0][3] = -prices[0];
        dp[0][4] = 0;
        for (int i = 1; i < len; i++) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1] + prices[i]);
            dp[i][3] = max(dp[i-1][3], dp[i-1][2] - prices[i]);
            dp[i][4] = max(dp[i-1][4], dp[i-1][3] + prices[i]);
        }

        return max(dp[len-1][2], dp[len-1][4]);
    }
};

// Solution2:

// dp[i]的值有两种可能：
// 第一，第i天完成第k笔买和卖，第k笔收益为0。
// 第二，第i天完成第k笔的卖出，之前的一些天完成其他交易。满足这种要求的所有情况，都能和第i-1天完成第k笔交易的情况建立一对一的关系，只是第k笔交易的卖出价格由prices[i - 1]变为了prices[i]。所以dp[i] = dp[i - 1] - prices[i - 1] + prices[i]。

// 作者：yushuo-guan
// 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/10xing-dai-ma-gao-ding-tong-jie-by-yushuo-guan/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int len = prices.size();

        vector<int> dp(len, 0);
        int k = 2;
        // 可能总共完成交易的此时是2， 1， 0次
        while (k-- >0) {
            // 在第i天完成第k笔交易
            for (int i = 1; i < len; i++) {
                dp[i] = max(dp[i], dp[i - 1] - prices[i - 1] + prices[i]);
            }
            // 在第i天前完成第k笔交易
            for (int i = 1; i < len; i++) {
                dp[i] = max(dp[i- 1], dp[i]);
            }
        }
        return dp[len - 1];
    }
};