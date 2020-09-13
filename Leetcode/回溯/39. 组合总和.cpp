// https://leetcode-cn.com/problems/combination-sum/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); i++) {
            vector<int> path;
            path.emplace_back(candidates[i]);
            int sum = candidates[i];
            dfs(ret, candidates, i, path, sum, target);
        }
        return ret;
    }

    void dfs(vector<vector<int>> &ret,
        const vector<int>& candidates,
        int start_index,
        vector<int> &path,
        int &sum,
        const int target) {
        if (sum > target)
            return;
        else if (sum == target) {
            ret.emplace_back(path);
            return;
        }

        for (int i = start_index; i < candidates.size(); i++) {
            path.emplace_back(candidates[i]);
            sum += candidates[i];
            dfs(ret, candidates, i, path, sum, target);
            sum -= candidates[i];
            path.pop_back();
        }
    }
};