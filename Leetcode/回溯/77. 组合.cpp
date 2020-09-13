// https://leetcode-cn.com/problems/combinations/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        if (n < k)
            return ret;
        int start_num_limit = n - k + 1;
        for (int i = 1; i <= start_num_limit ; i++) {
            vector<int> path;
            path.emplace_back(i);
            dfs(ret, path, i, n, k);
        }
        return ret;
    }

    void dfs(vector<vector<int>> &ret, vector<int> path, int start_num, const int &n, const int &k) {
        if (path.size() == k) {
            ret.emplace_back(path);
        }
        
        for (int i = start_num + 1; i <= n; i++) {
            path.emplace_back(i);
            dfs(ret, path, i, n, k);
            path.pop_back();
        }
    }
};