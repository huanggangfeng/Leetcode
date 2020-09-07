// https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect_impl(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash_map;
        vector<int> ret;
        for (auto &e : nums2) {
            if(hash_map.find(e) != hash_map.end())
                hash_map[e] += 1;
            else
                hash_map[e] = 1;   
        }

        for (auto &e : nums1) {
            auto it = hash_map.find(e);
            if ( it != hash_map.end()) {
                if (hash_map[e] >0) {
                    ret.emplace_back(e);
                    hash_map[e] -= 1;
                }
            }
        }
        return ret;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return intersect_impl(nums1, nums2);
        else
            return intersect_impl(nums2, nums1);
    }
};


class Solution {
public:
    vector<int> intersect_impl(vector<int>& nums1, vector<int>& nums2) {
        unordered_multiset<int> hash_table(nums2.begin(), nums2.end());
        vector<int> ret;
        for (auto &e : nums1) {
            auto it = hash_table.find(e);
            if ( it != hash_table.end()) {
                hash_table.erase(it);
                ret.emplace_back(e);
            }
        }
        return ret;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return intersect_impl(nums1, nums2);
        else
            return intersect_impl(nums2, nums1);
    }
};