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

// Solution：从头开始遍历，遇到每个元素，可以把它和后面的元素交换一次
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.empty())
            return ret;
        dfs(ret, nums, 0);
        return ret;
    }

    void swap(int &a, int &b) {
        int tmp = b;
        b = a;
        a= tmp;
    }

    void dfs(vector<vector<int>> &ret, vector<int>& nums, int start_pos) {
        if (start_pos == nums.size()) {
            ret.emplace_back(nums);
        }

        for (int i = start_pos; i < nums.size(); i++) {
                // 对于每个位置，不和后面元素交换也是一种状态
                swap(nums[start_pos], nums[i]);
                dfs(ret, nums, start_pos + 1);
                swap(nums[start_pos], nums[i]);
        }
    }
};
