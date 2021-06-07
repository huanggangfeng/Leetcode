// https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        if (nums.size() <= 1)
            return nums;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            if (nums[left] % 2 == 1)
                left++;
            else {
                int tmp = nums[right];
                nums[right] = nums[left];
                nums[left] = tmp;
                right--;
            }
        }
        return nums;
    }
};