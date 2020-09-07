// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        unordered_map<char, int> c_cnt;
        int ret = 1;
        int left = 0;
        int right = 0;
        while (right < s.size()) {
            char c = s[right];
            c_cnt[c]++;
            right++;
            while (c_cnt[c] > 1) {
                char l = s[left];
                c_cnt[l]--;
                left++;
            }
            int len = right -left;
            if (len > ret)
                ret = len;
        }
        return ret;
    }
};