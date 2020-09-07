// https://leetcode-cn.com/problems/longest-consecutive-sequence/submissions/
/*
并查集
// [7, 5, 4, 8, 6]
Step 1: 7:1 // 第一次出现，以7开始或者以7为尾的连续子串长度是1
Step 2: 7:1
        5:1  // 同上
Step3:  7:1
        5:1
        4:1 
        // 插入4后， 发现4+1存在， pos-len = map[5]； 4-1不存在，所以all_len = post_len + 1, 只更新边界map[num - pre_len] 和map[num + pre_len], 都等于all
        5:1 -> 5:2
        4:2 -> 4:2
Step3:  7:1
        5:2
        4:2
        8:1
        // 7的len只能是它之前长度，因为8之前没有出现过，pre_len = map[7], post_len = 0, 9不存在，all = map[7] + 1 + 0 = 2; 更新map[nums - prelen] 和map[nums+ post_len]
        7:1->7:2
        8:1->8:2
Step3:  7:2
        5:2
        4:2
        8:2
        6:1 // 插入6:1， 发现num -1 存在，pre_len = map[5] = 2, post_len = map[7] = 2, all = pre_len + post_len + 1 = 5,  只更新边map[6-2] = 5, map[6+2] = 5;
        4:2->4:5
        8:2->8:5
*/                
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        unordered_map<int, int> hash_map;

        int ret = 0;
        for (auto &num : nums) {
            if (hash_map.find(num) == hash_map.end()) {
                hash_map[num] = 1;
                // 以num-1为尾的最长子序列的长度
                int pre_len = hash_map.find(num - 1) != hash_map.end() ? hash_map[num - 1] : 0;
                // 以num + 1为尾的最长子序列的长度
                int post_len = hash_map.find(num + 1) != hash_map.end() ? hash_map[num + 1] : 0;
                int all = post_len + pre_len + 1;
                hash_map[num - pre_len] = all;
                hash_map[num + post_len] = all;
                ret = max(ret, all);
            }
        }

        return ret;
    }
};
