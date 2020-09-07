// https://leetcode-cn.com/problems/find-peak-element/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.empty())
            return -1;
        if (nums.size() == 1)
            return 0;

        int left = INT_MIN;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] > left && nums[i] > nums[i+1])
                return i;
            else
                left = nums[i];
        }

        if (nums[nums.size() - 1] > left)
            return nums.size() -1;

        return -1;
    }
};