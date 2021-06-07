// https://leetcode-cn.com/problems/move-zeroes/


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        int left = 0;
        
        for(auto &e : nums) {
            if (e != 0) {
                nums[left++] = e;
            }
        }
        
        while (left < nums.size())
            nums[left++] = 0;
    }
};