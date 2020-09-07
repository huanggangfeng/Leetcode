// https://leetcode-cn.com/problems/group-anagrams/

// Solution: 每个字符串排序，然后依次插入hash表
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> hash_map;
        for (auto str : strs) {
            string tmp =str;
            sort(tmp.begin(), tmp.end());
            hash_map[tmp].push_back(str);
        }
        
        auto it = hash_map.begin();
        while (it != hash_map.end()) {
            ret.emplace_back(it->second);
            it++;
        }

        return ret;
    }
};