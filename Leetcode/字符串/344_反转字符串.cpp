// https://leetcode-cn.com/problems/reverse-string/

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size() <= 1)
            return;
        int left = 0;
        int right = s.size() -1;
        while (left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
};