// https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/

// 有个case会超时
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() && !word.empty())
            return false;
        if (word.empty())
            return true;
        int m = board.size();
        int n = board[0].size();
        int ret = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // cout << i << ":" << j << "\n";
                string path;
                vector<vector<int>> used(m, vector<int>(n, 0));
                if (board[i][j] == word[0]) {
                    path = board[i][j];
                    used[i][j] = 1;
                    ret = dfs(board, word, path, used, i, j);
                }
                if (ret)
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, const string &word, string path, vector<vector<int>> &used, int i, int j) {
        // cout << "path:" << path << "\n";
        if (path.size() == word.size())
            return true;

        vector<vector<int>> steps = {{-1, 0}, {1, 0}, {0, -1}, {0, +1}};
        for (auto &e : steps) {
            int x = i + e[0];
            int y = j + e[1];

            if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size())
                continue;
            // cout << x  << ":" << y <<"\n";
            if (board[x][y] != word[path.size()] || used[x][y] == 1)
                continue;
            used[x][y] = 1;
            // cout << x << ":" << y << ":\t" << used[x][y] << "\n";
            bool ret = dfs(board, word, path + board[x][y], used, x, y);
            if (ret)
                return true;
            used[x][y] = 0;
        }
        return false;;
    }
};