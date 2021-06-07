// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size())
            return 0;
        int cur = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[cur])
                nums[++cur] = nums[i];
        }
        return cur + 1;
    }
};