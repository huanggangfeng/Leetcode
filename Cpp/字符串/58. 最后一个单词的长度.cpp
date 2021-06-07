// https://leetcode-cn.com/problems/length-of-last-word/
class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.empty())
            return 0;
        
        int i = s.size() - 1;
        int end = s.size();
        while (i >=0 && s[i] == ' ') {
            i--;
            end--;
        }

        int start = i;
        while (i >=0 && s[i] != ' ') {
            i--;
            start--;
        }

        return end - (start + 1);
    }
};