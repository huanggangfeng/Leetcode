// https://leetcode-cn.com/problems/word-search/

// 经典回溯
class Solution {
private: 
    bool found = false;
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty())
            return false;
        if (word.empty())
            return true;
        int n  = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == word[0]) {
                    string path;
                    path += board[i][j];
                    vector<vector<int>> used(n, vector<int>(m, 0));
                    used[i][j] = 1;
                    dfs(board, word, path, used, i, j);
                    if (found)
                        return true;
                }
            }
        }
        return found;
    }

    vector<vector<int>> next_pos = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>>& board, const string &word, string path, vector<vector<int>> &used, int i, int j) {
        int index = path.size() - 1;
        if (word[index] != path[index])
            return;
        if (found || path == word) {
            found = true;
            return;
        }

        for (auto &e : next_pos) {
            int n = i + e[0];
            int m = j + e[1];
            if (n >= 0 && n < board.size() && m >=0 && m < board[0].size() && used[n][m] == 0 && found == false) {
                used[n][m] = 1;
                dfs(board, word, path + board[n][m], used, n, m);
                used[n][m] = 0;
            }
        }
    }
};