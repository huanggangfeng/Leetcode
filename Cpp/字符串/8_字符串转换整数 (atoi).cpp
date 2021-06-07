// https://leetcode-cn.com/problems/string-to-integer-atoi/

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty())
            return 0;
        int pos = 0;
        int index = 0;
        bool sigal = false;
        while(index < str.size()) {
            if (str[index] == ' ' && !sigal && !pos)
                index++;
            else if ((str[index] == '-' || str[index] == '+') && pos == 0) {
                sigal = true;
                str[pos++] = str[index++];
            } else if (str[index] >= '0' && str[index] <= '9') {
                str[pos++] = str[index++];
            } else 
                break;
        }

        if (pos == 0)
            return 0;
        
        long ret = 0;
        index = sigal ? 1 : 0;
        bool negative = (str[0] == '-') ? true : false;
        for (; index < pos; index++) {
            ret = ret * 10 + (str[index] - '0');
            if (ret > INT_MAX)
                break;
        }
        
        ret = str[0] == '-' ? ret * -1 : ret;
        if (ret > INT_MAX)
            ret = INT_MAX;
        else if (ret < INT_MIN)
            return INT_MIN;
        return ret;
    }
};