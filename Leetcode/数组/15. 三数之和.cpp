// https://leetcode-cn.com/problems/3sum/

class Solution {
public:
    // [left, right]
    vector<vector<int>> twoSum(vector<int>& nums, int left, int right, int target) {
        vector<vector<int>> ret;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum > target) {
                int value = nums[right];
                right--;
                while (right >= left && nums[right] == value){
                    right--;
                }
            } else if (sum < target) { 
                int value = nums[left];
                left++;
                while (right >= left && nums[left] == value) {
                    left++;
                }
            } else {
                int l_value = nums[left];
                int r_value = nums[right];
                vector<int> tmp{0-target, l_value, r_value};
                ret.emplace_back(tmp);
                right--;
                left++;
                while (right >= left && nums[right] == r_value){
                    right--;
                }
                while (right >= left && nums[left] == l_value) {
                    left++;
                }
            }
        }
        return ret;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3)
            return vector<vector<int>>{};
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0)
                break;
            vector<vector<int>> tmp = twoSum(nums, i + 1, nums.size() - 1, 0 - nums[i]);
            // cout << "target:left:right:" << nums[i] << "\n";
            for (auto &e : tmp)
                ret.emplace_back(e);
            while (nums[i+1] == nums[i] && i < nums.size() -2)
                i++;
        }
        return ret;
    }
};