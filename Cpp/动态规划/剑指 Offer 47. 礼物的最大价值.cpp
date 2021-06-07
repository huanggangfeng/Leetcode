// https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/

// 经典的dp问题

// 二维数组dp
// dp[i][j] = grid[i][j] + max(dp[i-1][j], dp[i][j-1])
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        // 列
        int row = grid[0].size();
        int column = grid.size();
        int value[column][row];

        value[0][0] = grid[0][0];
        for (int j = 1; j < row; j++) {
            value[0][j] = grid[0][j] + value[0][j-1];
        }
    
        for (int j = 1; j < column; j++)
            value[j][0] = grid[j][0] + value[j-1][0];

        for (int i = 1; i < column; i++) {
            for (int j = 1; j < row; j++) {
                value[i][j] = value[i-1][j] > value[i][j - 1]?
                    value[i-1][j] + grid[i][j]: value[i][j-1] + grid[i][j];
            }
        }
	    return value[column-1][row-1];
    }
};


// dp[i][j] = grid[i][j] + max(dp[i-1][j], dp[i][j-1]) 可以滚动数组，将二维优化成一维数组
// 当到达i，j位置的时候，
// dp[0, i-1]已经是新一行值了，dp[i, n]其实还是上一行的值 所以，
// dp[i-1][j] -> dp[j], 
// dp[i][j-1] -> dp[j-1]

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        if (grid.size() == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, 0);
        dp[0] = grid[0][0];
        for (int j = 1; j < n; j++)
            dp[j] = dp[j-1] + grid[0][j];


        for (int i = 1; i < m; i++) {
            dp[0] = dp[0] + grid[i][0];
            for (int j = 1; j < n; j++) {
                // dp[i][j-1] 或者 dp[i-1][j]
                dp[j] = dp[j-1] > dp[j] ? grid[i][j] + dp[j-1] : grid[i][j] + dp[j];
            }
        }
        return dp[n-1];
    }
};