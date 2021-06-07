// 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

// 你可以对一个单词进行如下三种操作：

// 插入一个字符
// 删除一个字符
// 替换一个字符
//  

// 示例 1：

// 输入：word1 = "horse", word2 = "ros"
// 输出：3
// 解释：
// horse -> rorse (将 'h' 替换为 'r')
// rorse -> rose (删除 'r')
// rose -> ros (删除 'e')
// 示例 2：

// 输入：word1 = "intention", word2 = "execution"
// 输出：5
// 解释：
// intention -> inention (删除 't')
// inention -> enention (将 'i' 替换为 'e')
// enention -> exention (将 'n' 替换为 'x')
// exention -> exection (将 'n' 替换为 'c')
// exection -> execution (插入 'u')

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/edit-distance
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // dp[i][j]表示将字符串1 中的子串[0, i) -> 字符串2的子串[0, j) 所需要的最少次数
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, n + m));
        dp[0][0] = 0;
        // word1 的子串[0, i)转为空串, 只要把字符删掉, dp[i][0] = i
        for (int i = 1; i <= n; i++)
            dp[i][0] = i;
        
        // 从空串转为word2 的子串[0, i), 只要把每个字符加上去即可, dp[i][0] = i
        for (int i = 1; i <= m; i++)
            dp[0][i] = i;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // dp[i -1] == dp[j - 1], 其实只需要将[0, i - 1) ->[0, j - 1)即可
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    // 三种方法: 
                    // 1. 已知 source[0, i - 1) 转换成target[0, j)的步骤, 可以把[0, i) 删去最后一个字符,再转换成target 串
                    int top = 1 + dp[i - 1][j];
                    // 2. 已知 source[0, i) 转换成target[0, j - 1)的步骤, 可以把[0, i) 转换成target[0, j - 1), 再insert一个字符即可实现target 串
                    int left = dp[i][j - 1] + 1;
                    // 2. 已知 source[0, i - 1) 转换成target[0, j - 1)的步骤, 可以把[0, i - 1) 转换成target[0, j - 1), 再替换掉最后一个字符即可
                    int leftTop = dp[i - 1][j - 1] + 1;
                    dp[i][j] = min(min(top, left), leftTop);
                }
            }
        }

        return dp[n][m];
    }
};

// 滚动数组优化
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // 最差情况, 使用n步把word1的所有字母删光,再用m步把word2的每个字母加进去, 
        vector<int> dp(m + 1, n + m);
        for (int i = 0; i <= m; i++)
            dp[i] = i;

        for (int i = 1; i <= n; i++) {
            dp[0] = i;
            // lefttop 纪录的是左上角的值,这里因为是一维数组, 所以其实就是dp[i - 1]的前一次value
            int leftTop = dp[0] - 1;
            for (int j = 1; j <= m; j++) {
                // 当前将要被override, 所以先纪录下来,
                int curr = dp[j];
                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = leftTop; // 左上角
                } else {
                    // dp[i] 还没有被覆写,所以其实就是dp[i - 1][j]
                    int top = dp[j];
                    // dp[j - 1] 上一步已经更新, 其实就是dp[i][j - 1]
                    int left = dp[j - 1];
                    dp[j] = min(min(top, left), leftTop) + 1;
                }
                // 更新lefttop, 其实也就是把dp[j]的旧值 留给下一次更新dp[j + 1] 的时候作为topleft
                leftTop = curr;
            }
        }

        return dp[m];
    }
};

作者：huanggangfeng
链接：https://leetcode-cn.com/problems/edit-distance/solution/dong-tai-gui-hua-yi-ji-gun-dong-shu-zu-you-hua-che/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。