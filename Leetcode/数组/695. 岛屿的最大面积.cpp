// https://leetcode-cn.com/problems/max-area-of-island/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ret = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int area = getArea(grid, i, j);
                    ret = max(ret, area);
                }
            }
        }
        return ret;
    }

    int getArea(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m)
            return 0;
        int ret = 1;
        if (grid[i][j] != 1)
            return 0;

        grid[i][j] = 0;
        ret += getArea(grid, i - 1, j) +getArea(grid, i + 1, j) + getArea(grid, i, j-1) + getArea(grid, i, j+1) ;
        return ret;
    }
};