// https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        if (nums.size() < 2)
            return ret;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int val = nums[left] + nums[right];
            if (val > target)
                right--;
            else if (val < target)
                left++;
            else {
                ret.emplace_back(nums[left]);
                ret.emplace_back(nums[right]);
                break;
            }
        }
        return ret;
    }
};