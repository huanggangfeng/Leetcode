// https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
class Solution {
public:
    // [left, right]
    void reverse(string &s, int left, int right) {
        while (left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
    string reverseWords(string s) {
        if (s.size() <= 1)
            return s;
        int left = 0;
        int right;
        for (int i = 0; i < s.size(); ) {
            if (s[i] == ' ') {
                reverse(s, left, i-1);
                i++;
                while (s[i] == ' ' && i < s.size()) {
                    i++;
                }
                left = i;

            } else
                i++;
        }
        reverse(s, left, s.size() -1);
        return s;
    }
};