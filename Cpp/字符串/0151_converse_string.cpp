// https://leetcode-cn.com/problems/reverse-words-in-a-string/

class Solution {
public:
    // Reverse the string [left, right)
    void reverse(string &s, int left, int right) {
        if (s.empty())
            return;
        right--;
        while (left < right) {
            char tmp = s[right];
            s[right] = s[left];
            s[left] = tmp;
            left++;
            right--;
        }
    }
    string reverseWords(string s) {
        if (s.empty())
            return "";
        // the length after remove all spaces
        int len = 0;
        int current = 0;
        bool prevIsSpace = true; // default is true, we suppose s[-1] is space
        // remove all spaces
        for (int i = 0; i < s.size(); i++) {
            // s[i] is not space, move it to the current index
            if (s[i] != ' ') {
                s[current++] = s[i];
                prevIsSpace = false;
            } else if (!prevIsSpace) {
                // This is the 1st space in the string, move it to the current index
                s[current++] = ' ';
                prevIsSpace = true;
            }
        }
        // if there are some spaces at the end of the string, remove it
        len = prevIsSpace ? current - 1 : current;
        // To handle the case that input is all spaces : "    "
        if (len <= 0)
            return "";

        // Reverse the string [left, right)
        reverse(s, 0, len);
        // cout << "tgtt:" << s.substr(0, len) << "***";
        int prevSpaceIndex = -1;
        int currentSpaceIndex = 0;
        // reverse every word, this loop will converse all word except the last one
        for (int i = 0; i < len; i++) {
            if (s[i] == ' ') {
                reverse(s, prevSpaceIndex + 1, i);
                prevSpaceIndex = i;
            }
        }
        // need to handle the last word
        reverse(s, prevSpaceIndex + 1, len);
        return s.substr(0, len);
    }
};