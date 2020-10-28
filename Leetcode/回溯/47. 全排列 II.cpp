class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.empty())
            return ret;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            vector<int> used(len, 0);
            vector<int> path;
            used[i] = 1;
            path.emplace_back(nums[i]);
            dfs(ret, nums, used, path);
        }
        return ret;
    }

    void dfs(vector<vector<int>> &ret, vector<int>& nums, vector<int> &used, vector<int> &path) {
        if (path.size() == nums.size()) {
            ret.push_back(path);
        }

        int prev_index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;
            // 同一层中某个数只能使用一次， 所以这里是used[i-1] 要为false，因为这里是在回溯，
            // 只有used[i-1] 在这里没用过，才能说明它在本层循环中 已经被使用过一次了
            // [3, 3, 3, 4]为例子：
            // i = 0; used[0] == 1, 直接continue，index 0首层循环已经使用过了
            // i = 1; 虽然nums[i] == nums[i-1], 并且used[i]未被使用, 但是use[i-1]为1，说明数字3在i之前出现的都被前面层使用了，本层数字3是第一次出现，所以可以加到path
            // i = 2； nums[i] == nums[i-1], 但是它非本层的第一个unused 3，所以continue
            // i = 3; 
            if(i > 0 && !used[i-1] && nums[i] == nums[i-1])
                continue;
            path.push_back(nums[i]);
            used[i] = 1;
            dfs(ret, nums, used, path);
            used[i] = 0;
            path.pop_back();
        }
    }
};


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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

    void dfs(vector<vector<int>> &ret, vector<int>& nums, int level) {
        if (level == nums.size()) {
            ret.emplace_back(nums);
            return;
        }
        for (int i = level; i < nums.size(); i++) {
                if (isReapted(nums, level, i))
                    continue;

                swap(nums[level], nums[i]);
                dfs(ret, nums, level + 1);
                swap(nums[level], nums[i]);
        }
    }

    // 在当前数字和前面已经处理过的某个数字一样，所以是重复处理，可以剪枝
    bool isReapted(vector<int>& nums, int level, int i) {
        for (int j = level; j < i ; j++) {
            if (nums[j] == nums[i])
                return true;
        }
        return false;
    }
};