// https://leetcode-cn.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() <= 1)
            return {-1,-1};
        unordered_map<int, int> hash_map;
        hash_map[ nums[0]] = 0;
        for (int i = 1; i < nums.size(); i++) {
            int expected_value = target - nums[i];
            auto it = hash_map.find(expected_value);
            if (it != hash_map.end())
                return {it->second, i};
            else
                hash_map[nums[i]] = i; 
        }
        return {-1,-1};
    }
};