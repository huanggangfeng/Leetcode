// https://leetcode-cn.com/problems/stone-game/

// 思路和486完全一样
// https://leetcode-cn.com/problems/predict-the-winner/
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int len = piles.size();
        int dp[len][len];
        for (int i = 0; i < len; i++) {
            dp[i][i] = piles[i];
        }

        for (int i = len - 2; i >= 0; i--) {
            for (int j = i + 1; j < len; j++)
                dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]);
        }
        return dp[0][len-1] > 0;
    }
};