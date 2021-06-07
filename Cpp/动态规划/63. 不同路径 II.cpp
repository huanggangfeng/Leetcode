// https://leetcode-cn.com/problems/unique-paths-ii/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty())
            return 0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        int dp[n][m];
        bool has_obstacle = false;
        if (obstacleGrid[0][0]) {
             return 0;
        }

        dp[0][0] = 1;
        for (int i = 1; i < m; i++) {
            if (!has_obstacle && !obstacleGrid[0][i])
                dp[0][i] = 1;
            else { 
                has_obstacle = true;
                dp[0][i] = 0;
            }
        }
        
        has_obstacle = false;
        for (int i = 1; i < n; i++) {
            if (!has_obstacle && !obstacleGrid[i][0])
                dp[i][0] = 1;
            else { 
                has_obstacle = true;
                dp[i][0] = 0;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }

        return dp[n-1][m-1];
    }
};