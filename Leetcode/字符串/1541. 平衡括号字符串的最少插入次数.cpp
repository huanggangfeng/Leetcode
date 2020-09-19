// https://leetcode-cn.com/problems/minimum-insertions-to-balance-a-parentheses-string/
class Solution {
public:
    int minInsertions(string s) {
        int left_num = 0;
        int ret = 0;
        int i = 0;
        while (i < s.size()) {
            char ch = s[i];
            if (ch == '(') {
                left_num++;
                i++;
            } else if (ch == ')') {
                if (i + 1 < s.size() && s[i+1] == ')') {
                    left_num--;
                    i += 2;
                } else {
                    ret++;
                    left_num--;
                    i++;
                }

                if (left_num == -1) {
                    left_num = 0;
                    ret += 1;
                }
            }
        }
        ret += left_num * 2;
        return ret;
    }
};