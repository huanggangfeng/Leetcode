// https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> count(26, 0);
        char ret = ' ';
        if (s.empty())
            return ret;
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (count[s[i]- 'a'] ==1)
                return s[i];
        }
        return ret;
    }
};