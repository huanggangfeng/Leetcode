// https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return -1;
        if (nums.size() == 1)
            return nums[0];
        int pre_max = nums[0];
        int ret = nums[0];
        for (int i = 1; i< nums.size(); i++) {
            pre_max = nums[i] > pre_max + nums[i] ? nums[i] : pre_max + nums[i];
            ret = pre_max > ret ? pre_max : ret;
        }            
        return ret;  
    }
};