// 给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。

// 字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

// 题目数据保证答案符合 32 位带符号整数范围。

//  

// 示例 1：

// 输入：s = "rabbbit", t = "rabbit"
// 输出：3
// 解释：
// 如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
// (上箭头符号 ^ 表示选取的字母)
// rabbbit
// ^^^^ ^^
// rabbbit
// ^^ ^^^^
// rabbbit
// ^^^ ^^^
// 示例 2：

// 输入：s = "babgbag", t = "bag"
// 输出：5
// 解释：
// 如下图所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
// (上箭头符号 ^ 表示选取的字母)
// babgbag
// ^^ ^
// babgbag
// ^^    ^
// babgbag
// ^    ^^
// babgbag
//   ^  ^^
// babgbag
//     ^^^

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/distinct-subsequences
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// https://leetcode-cn.com/problems/distinct-subsequences/solution/c-9847-er-wei-dong-tai-gui-hua-10xing-yi-wei-dong-/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = t.size();
        int m = s.size();
        // t[0, i) 在 s[0, j)的子串中出现的次数
        vector<vector<long>> dp(n + 1, vector<long>(m +1, 0));
        // 空串是所有串的子串
        for (int i = 0; i <= m; i++) {
            dp[0][i] = 1;
        }

        for (int i = 1; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (t[i - 1] == s[j - 1])
                    dp[i][j] = dp[i][j - 1]  + dp[i- 1][j -1];
                else
                    dp[i][j] = dp[i][j - 1];
            }
        }
        return dp[n][m];
    }
};