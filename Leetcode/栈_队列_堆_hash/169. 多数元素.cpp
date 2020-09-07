// https://leetcode-cn.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int middle = (nums.size() + 1) /2;
        for (int &e : nums) {
            // ++freq[e];
            if (++freq[e] >= middle)
                return e;
        }
        return 0;
    }
};