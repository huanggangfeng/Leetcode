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



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if (nums.size() < 3)
            return ret;
        sort(nums.begin(), nums.end());
        int n = nums.size() - 2;
        for (int i = 0; i < n; i++) {
            // 在计算第一个数字为nums[i -1]的时候，num[i]..[end]所有的两两数据都统计过了，比如[i + 1, n)都统计过了，所以不用再次计算
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if (nums[i] > 0)
                return ret;

            int left = i + 1;
            int right = nums.size() - 1;
            int target = 0 - nums[i];
            while (left < right) {
                int sum2 = nums[left] + nums[right];
                if (sum2 == target) {
                    ret.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                    while (left < right && nums[left] == nums[left-1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                } else if (sum2 > target) {
                        right--;
                } else {
                        left++;
                }
            }
        }
        return ret;
    }
};