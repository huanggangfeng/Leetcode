// https://leetcode-cn.com/problems/number-of-islands/

// 1. 深度优先
// 2. 广度优先
// 3. 并查集

//  这里只是实现了一个DFS算法
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty())
            return 0;
        int ret = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ret++;
                }
            }
        }
        return ret;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        int x,y;
        x = i - 1;
        y = j;
        if (x >= 0 && grid[x][y] == '1')
            dfs(grid, x, y);

        x = i + 1;
        if (x < grid.size() && grid[x][y] == '1')
            dfs(grid, x, y);
        
        x = i;
        y = j - 1;
        if (y >= 0 && grid[x][y] == '1')
            dfs(grid, x, y);

        y = j + 1;
        if (y < grid[0].size() && grid[x][y] == '1')
            dfs(grid, x, y);
    }
};