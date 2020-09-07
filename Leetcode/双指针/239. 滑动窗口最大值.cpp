// https://leetcode-cn.com/problems/sliding-window-maximum/

class Solution {
public:
    // 找出 [left, right]中最大值的index
    int find_max(vector<int> &nums, int left, int right, int old_max_index) {
        if (old_max_index >= left) {
            return nums[old_max_index] > nums[right] ? old_max_index : right; 
        }
        int ret = left;
        left++;
        while (left <= right) {
            if (nums[left] > nums[ret])
                ret = left;
            left++;
        }
        return ret;
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty())
            return vector<int>{};
        // 总共有nums.size() - k  + 1 个窗口
        int windows_num = nums.size() - k  + 1;

        int max_index = 0;
        for (int i = 1; i < k; i++) {
            if (nums[i] > nums[max_index])
                max_index = i;
        }

        vector<int> ret;
        ret.emplace_back(nums[max_index]);

        for (int i = 1; i < windows_num; i++) {
            max_index = find_max(nums, i, i + k - 1, max_index);
            ret.emplace_back(nums[max_index]);
        }

        return ret;
    }
};