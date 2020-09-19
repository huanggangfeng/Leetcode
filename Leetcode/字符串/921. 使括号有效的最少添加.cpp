// https://leetcode-cn.com/problems/minimum-add-to-make-parentheses-valid/solution/bu-xu-yao-zhan-zhi-bian-li-yi-ci-100-94-by-huanggf/
class Solution {
public:
    int minAddToMakeValid(string S) {
        if (S.empty())
            return 0;
        int ret = 0;
        int left_num = 0;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '(')
                left_num++;
            else if (S[i] == ')')
                left_num--;
            if (left_num == -1) {
                ret++;
                left_num = 0;
            }
        } 
        ret += left_num;
        return ret;
    }
};