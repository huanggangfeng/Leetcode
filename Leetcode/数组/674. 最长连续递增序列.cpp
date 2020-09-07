// https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums.size();
        int ret = 1;
        int left = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1])
                ret = max(ret, i - left + 1);
            else
                left = i;
        }
        return ret;
    }
};