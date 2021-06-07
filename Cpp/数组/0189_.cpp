// 189. 旋转数组

// https://leetcode-cn.com/problems/rotate-array/

class Solution {
public:
    // rotate nums[left, right]
    void rotate_internal(vector<int>& nums, int left, int right) {
        while (left < right) {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        if (nums.size() <= 1)
            return;
        // k 大于数组的size，k对数组size取余，因为旋转size次其实数组又回到了原来位置
        if (k > nums.size())
            k = k % nums.size();
        rotate_internal(nums, 0, nums.size() - 1);
        rotate_internal(nums, 0, k-1);
        rotate_internal(nums, k, nums.size() - 1);
    }
};