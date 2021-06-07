// https://leetcode-cn.com/problems/search-insert-position/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;
        int left = 0;
        int right = nums.size() -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target)
                left = mid + 1;
        }

        return left;
    }
};