// https://leetcode-cn.com/problems/longest-valid-parentheses/

// https://leetcode-cn.com/problems/longest-valid-parentheses/solution/dong-tai-gui-hua-san-bu-zou-kan-liao-hen-ming-bai-/


 // dp[i] 表示已s[i]结尾的最长连续有效括号
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
                // 如果s[i-1]可以和s[i]匹配,那么dp[i] = dp[i - 2] + 2
                if (s[i-1] == '(') {
                    dp[i] = i >= 2 ? dp[i-2] + 2 : 2;
                } else if (s[i-1] == ')') {
                    // 判断s[i] 能不能和dp[i-1]对应的字符串[j, i - 1]前面的一个字符s[j-1]形成匹配
                    int prevIndex = i - dp[i-1] - 1;
                    if (prevIndex >= 0 && s[prevIndex] == '(') {
                        if (prevIndex - 1 >= 0)
                            // 如果可以匹配的，可能会把j-1之前的字符串，j, 以及[j, i - 1], i连接成一个更长的有效串，
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