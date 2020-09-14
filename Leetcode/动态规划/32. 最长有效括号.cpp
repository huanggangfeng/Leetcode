// https://leetcode-cn.com/problems/longest-valid-parentheses/

// https://leetcode-cn.com/problems/longest-valid-parentheses/solution/dong-tai-gui-hua-san-bu-zou-kan-liao-hen-ming-bai-/

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.size();
        if (len < 2)
            return 0;
        vector<int> dp(len, 0);
        int ret = 0;
        for (int i = 1; i < len; i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = i >= 2 ? dp[i-2] + 2 : 2;
                } else if (s[i-1] == ')') {
                    int prevIndex = i - dp[i-1] - 1;
                    if (prevIndex >= 0 && s[prevIndex] == '(') {
                        if (prevIndex - 1 >= 0)
                            dp[i] = dp[i-1] + dp[prevIndex-1] + 2;
                        else
                            dp[i] = dp[i-1] + 2;
                    }
                }
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};