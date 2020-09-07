// https://leetcode-cn.com/problems/intersection-of-two-arrays/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        if (nums1.empty() || nums2.empty())
            return ret;
        if (nums1.size() >= nums2.size())
            find_intersection(nums1, nums2, ret);
        else
            find_intersection(nums2, nums1, ret); 
        return ret;
    }

    void find_intersection(vector<int>& nums1, vector<int>& nums2, vector<int>& result) {
        unordered_set<int> s;
        unordered_set<int> ret;
        for (auto &e : nums2)
            s.emplace(e);
        for (auto &e : nums1) {
            if (s.find(e) != s.end())
                ret.emplace(e);
        }
        result.assign(ret.begin(), ret.end());
    }
};