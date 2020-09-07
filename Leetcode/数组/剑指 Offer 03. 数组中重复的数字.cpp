// https://leetcode-cn.com/problems/shu-zu-zhong-zhong-fu-de-shu-zi-lcof/

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i) {
                if (nums[nums[i]] == nums[i])
                    return nums[i];
                else {
                    int tmp = nums[nums[i]];
                    nums[nums[i]] = nums[i];
                    nums[i] = tmp;
                } 
            }
        }
        return -1;
    }
};


class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto &e : nums) {
            if (++m[e] >=2)
                return e;
        }
        return -1;
    }
};