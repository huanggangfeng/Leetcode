// https://leetcode-cn.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <= 1)
            return false;
        set<int> s;
        for (auto &e: nums) {
            if (s.find(e) != s.end())
                return true;
            s.insert(e);
        }
        return false;
    }
};