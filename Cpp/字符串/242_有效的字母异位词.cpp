// https://leetcode-cn.com/problems/valid-anagram/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.empty() && t.empty())
            return true;

        unordered_map<char, int> hash_map;
        for (int i = 0; i< s.size(); i++)
            hash_map[s[i]] += 1;

        for (int i = 0; i < t.size(); i++) {
            if (hash_map.find(t[i]) == hash_map.end())
                return false;
            else 
                hash_map[t[i]] -= 1;
        }
        
        for (auto it : hash_map) {
            if (it.second != 0)
                return false;
        }

        return true;
    }
};