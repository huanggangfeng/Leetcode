// https://leetcode-cn.com/problems/combination-sum-ii/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        if (candidates.empty())
            return ret;
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); i++) {
            // 大剪枝， 每次开始的数字都不一样
            if (i > 0 && candidates[i] == candidates[i-1])
                continue;
            vector<int> path;
            path.emplace_back(candidates[i]);
            dfs(ret, candidates, path, i + 1, target - candidates[i]);
        }
        return ret;
    }

    void dfs(vector<vector<int>> &ret, vector<int>& candidates, vector<int> &path, int start_pos, int  target) {
        if (target < 0)
            return;
        else if (target == 0) {
            ret.emplace_back(path);
            return;
        }

        for (int i = start_pos; i < candidates.size(); i++) {
            //小剪枝，保证当前层也不要重复出现相同数字
            if (i > start_pos && candidates[i] == candidates[i-1])
                continue;
            path.emplace_back(candidates[i]);
            dfs(ret, candidates, path, i +1, target - candidates[i]);
            path.pop_back();
        }
    }
};