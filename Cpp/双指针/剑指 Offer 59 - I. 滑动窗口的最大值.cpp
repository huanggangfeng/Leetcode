// https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if (nums.size() < k || nums.empty())
            return ret;
        ret.reserve(nums.size() - k + 1);
        int maxIndex = 0;
        for (int i = 1; i < k; i++) {
            if (nums[i] >= nums[maxIndex])
                maxIndex = i;
        }
        ret.emplace_back(nums[maxIndex]);
        for (int right = k, left = 1; right < nums.size(); left++, right++) {
            if (nums[right] >= nums[maxIndex])
                maxIndex = right;
            else if (maxIndex < left) {
                maxIndex = right;
                for (int i = left; i <= right; i++) {
                    if (nums[i] > nums[maxIndex])
                        maxIndex = i;
                }
            }
            ret.emplace_back(nums[maxIndex]);
        }
        return ret;
    }
};