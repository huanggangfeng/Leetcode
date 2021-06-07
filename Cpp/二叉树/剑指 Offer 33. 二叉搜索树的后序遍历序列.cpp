// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return helper(postorder, 0, postorder.size() - 1);
    }

    bool helper(vector<int> nums, int left, int right) {
        if (left >= right)
            return true;
        int mid = split(nums, left, right);
        if (mid == -1)
            return false;
        return helper(nums, left, mid -1) && helper(nums, mid, right - 1);

    }

    int split(vector<int> nums, int left, int right) {
        int ret;
        while (nums[left] < nums[right]) {
            left++;
        }
        ret = left;
        for (int i = ret; i < right; i++) {
            if (nums[i] < nums[right]) {
                ret = -1;
                break;
            }
        }
        return ret;
    }
};