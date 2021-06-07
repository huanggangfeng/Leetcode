
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/10xing-dai-ma-gao-ding-tong-jie-by-yushuo-guan/

// dp[i]的值有两种可能：
// 第一，第i天完成第k笔买和卖，第k笔收益为0。
// 第二，第i天完成第k笔的卖出，之前的一些天完成其他交易。满足这种要求的所有情况，都能和第i-1天完成第k笔交易的情况建立一对一的关系，只是第k笔交易的卖出价格由prices[i - 1]变为了prices[i]。所以dp[i] = dp[i - 1] - prices[i - 1] + prices[i]。

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len = prices.size();
        if (len <= 1)
            return 0;
        int ret = 0;
        // 问题退化成不限定交易次数, 贪心法当前最佳
        if (k >= len/2) {
            for(int i = 1; i < len; ++i)
            {
                if(prices[i] > prices[i - 1])
                    ret += prices[i] - prices[i - 1];
            }
            return ret;
        }
        
        vector<int> dp(len, 0);

        // 最多交易n次，也就意味着可能此时是：1， 2， 3， 4， 5， 都需要判断
        while(k-- > 0)
        {
            //第1个for循环中，dp[i]代表第i天完成前k次交易所能获得的最大价值。          
            for(int i = 1; i < len; ++i)
                dp[i] = max(dp[i - 1] - prices[i - 1] + prices[i], dp[i]);
            //第2个for循环中，dp[i]代表前i天完成前k次交易所能获得的最大价值。 
            for(int i = 1; i < len; ++i)
                dp[i] = max(dp[i], dp[i - 1]);
        }
        return dp[len - 1];
    }
};