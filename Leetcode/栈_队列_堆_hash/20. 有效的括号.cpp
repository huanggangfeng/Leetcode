// https://leetcode-cn.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s) {
        if (s.empty())
            return true;
        if (s.size() % 2 == 1)
            return false;
        std::stack<char> stack;
        stack.push(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stack.push(s[i]);
            else if (s[i] == ')') {
                if (stack.top() == '(')
                    stack.pop();
                else
                    return false;
            } else if (s[i] == '}') {
                if (stack.top() == '{')
                    stack.pop();
                else
                    return false;
            } else if (s[i] == ']') {
                if (stack.top() == '[')
                    stack.pop();
                else
                    return false;
            }
        }
        return stack.empty();
    }
};