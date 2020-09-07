// https://leetcode-cn.com/submissions/detail/91753670/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;
        int pos = -1;
        int left = 0;
        int right = nums.size() - 1;
        int middle = 0;
        while (left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] > target)
                right = middle - 1;
            else if (nums[middle] < target)
                left = middle + 1;
            else {
                pos = middle;
                break;
            } 
        }

        if (pos == -1)
            return 0;
        left = middle;
        right = middle;
        while (left >=0 && nums[left] == target)
            left--;
        while (right < nums.size() && nums[right] == target)
            right++;

        return right - left - 1;
    }
};