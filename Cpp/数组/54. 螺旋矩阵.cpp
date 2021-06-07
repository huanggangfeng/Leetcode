// https://leetcode-cn.com/problems/spiral-matrix/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if (matrix.empty())
            return ret;
        int left = 0;
        int right = matrix[0].size() - 1;
        int up = 0;
        int down = matrix.size() - 1;
        while (true) {
            //向右
            for (int i = left; i <= right; i++)
                ret.push_back(matrix[up][i]);
            if (++up > down)
                break;
            // 向下
            for (int i = up; i <= down; i++)
                ret.push_back(matrix[i][right]);
            if (--right < left)
                break;
            // 向左
            for (int i = right; i >= left; i--)
                ret.push_back(matrix[down][i]);
            if (--down < up)
                break;
            // 向上
            for (int i = down; i >= up; i--)
                ret.push_back(matrix[i][left]);
            if (++left > right)
                break;
        }
        return ret;
    }
};
