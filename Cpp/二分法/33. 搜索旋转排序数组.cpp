// https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            // [left, mid] 有序
            if (nums[mid] > nums[left]) {
                // target 在[left, mid) 之间
                if (target < nums[mid] && target >= nums[left]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < nums[left]){
                // (mid, right) 有序
                if (target > nums[mid] && target <= nums[right - 1]) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            } else {
                left++;
            }
        }
        return -1;
    }
};