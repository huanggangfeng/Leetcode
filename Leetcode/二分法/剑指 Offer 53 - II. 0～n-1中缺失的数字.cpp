// https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            // cout << "mid:" << mid << "\n";
            if (nums[mid] == mid)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};