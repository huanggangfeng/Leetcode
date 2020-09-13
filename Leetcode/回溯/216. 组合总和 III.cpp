// https://leetcode-cn.com/problems/combination-sum-iii/

//这类题的套路就是dfs + 回溯， 通常不能重复那就保证开始元素的唯一

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        if (k > n)
            return result;
        for (int i = 1; i <= 9 - k + 1; i++) {
            vector<int> path;
            path.emplace_back(i);
            dfs(result, path, i + 1, k, n - i);
        }
        return result;
    }

    void dfs(vector<vector<int>> &result, vector<int> &path, int start_num, const int k, int target) {
        if (target < 0)
            return;
        if (path.size() == k) {
            if (target == 0)
                result.emplace_back(path);
            return;
        }

        for (int i = start_num; i <= 9; i++) {
            path.emplace_back(i);
            dfs(result, path, i + 1, k, target - i);
            path.pop_back();
        }
    }
};