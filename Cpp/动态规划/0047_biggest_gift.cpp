// https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int dp[m][n];
        dp[0][0] = grid[0][0];
        for (int i = 1; i < n; i++)
            dp[0][i] = dp[0][i-1] + grid[0][i];
        for (int i = 1; i < m; i++)
            dp[i][0] = dp[i-1][0] + grid[i][0];
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // 前一步是dp[i][j-1] 或者 dp[i-1][j]
                if (dp[i][j-1] > dp[i-1][j])
                    dp[i][j] = dp[i][j-1] + grid[i][j];
                else
                    dp[i][j] = dp[i-1][j] + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

// 优化： grid可以被复用，所以可以不用开辟新的dp二维数组，直接覆盖grid即可
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 1; i < n; i++)
            grid[0][i] += grid[0][i-1];
        for (int i = 1; i < m; i++)
            grid[i][0] += grid[i-1][0];
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // 上一步为dp[i][j-1] 或者 dp[i-1][j]
                 grid[i][j] += grid[i][j-1] > grid[i-1][j]? grid[i][j-1] : grid[i-1][j];
            }
        }
        return grid[m-1][n-1];
    }
};