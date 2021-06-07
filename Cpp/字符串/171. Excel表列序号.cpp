// https://leetcode-cn.com/problems/excel-sheet-column-number/
class Solution {
public:
    int titleToNumber(string s) {
        if (s.empty())
            return 0;
        int ret = 0;
        for (int i = 0; i < s.size(); i++) {
            ret = ret * 26 + (s[i] - 'A' + 1);
        }
        return ret;
    }
};