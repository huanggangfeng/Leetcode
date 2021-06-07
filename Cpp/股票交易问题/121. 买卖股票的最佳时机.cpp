class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int maxProfit = 0;
        int lowestPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < lowestPrice)
                lowestPrice = prices[i];
            else
                maxProfit = max(maxProfit, prices[i] - lowestPrice);
        }

        return maxProfit;
    }
};