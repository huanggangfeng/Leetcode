//  https://leetcode-cn.com/problems/valid-palindrome/

class Solution {
public:
    // string[left, right]
    bool isPalindrome_impl(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    bool isPalindrome(string s) {
        if (s.size() <= 1)
            return true;

        transform(s.begin(), s.end(), s.begin(), ::tolower);

        int left = 0;
        for (int index = 0; index< s.size(); index++) {
            if(isalnum(s[index])) {
                s[left++] = s[index];
            }
        }

        left = left > 0? left-1: 0;
        return isPalindrome_impl(s, 0, left);
    }
};