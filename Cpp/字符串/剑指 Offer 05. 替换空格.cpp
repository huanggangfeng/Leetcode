// https://leetcode-cn.com/problems/ti-huan-kong-ge-lcof/
class Solution {
public:
    string replaceSpace(string s) {
        if (s.empty())
            return s;
        int count = 0;
        int i = 0;
        for (; i < s.size(); i++) {
            if (s[i] == ' ')
                count++;
        }
        count = count * 2 + s.size(); 
        i = s.size() - 1;
        s.resize(count);
        count--;

        while(i >= 0) {
            if (s[i] != ' ') {
                s[count] = s[i];
                count--;
            } else {
                s[count] = '0';
                s[count - 1] = '2';
                s[count - 2] = '%';
                count = count - 3;
            }
            i--;
        }
        return s;
    }
};