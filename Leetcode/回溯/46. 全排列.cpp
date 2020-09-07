// https://leetcode-cn.com/problems/permutations/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.empty())
            return ret;
        vector<int> temp;
        vector<int> used(nums.size(), 0);
        int usedNum = 0;
        dfs(ret, nums, temp, used, 0);
        return ret;
    }

    void dfs(vector<vector<int>> &result, vector<int>& nums, vector<int> &path, vector<int> &used, int level) {
        if (level == nums.size()) {
            result.emplace_back(path);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;
            else {
                path.push_back(nums[i]);
                used[i] = 1;
                dfs(result, nums, path, used, level + 1);
                used[i] = 0;
                path.pop_back();
            }
        }
        return;
    }
};
