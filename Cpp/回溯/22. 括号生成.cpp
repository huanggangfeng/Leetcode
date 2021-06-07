// https://leetcode-cn.com/problems/generate-parentheses/submissions/

// dfs
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if (n == 0)
            return ret;

        dfs(ret, "", n, n, 2*n); 
        return ret;

    }
    void dfs(vector<string> &ret, string path, int open, int close, const int target) {
        if (path.size() == target) {
            ret.emplace_back(path);
            return;
        }

        if (open > 0) {
            dfs(ret, path + '(', open - 1, close, target);
        }

        if (close > open) {
             dfs(ret, path + ')', open, close -1, target);
        }
    }
};

// backtrace
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0)
            return result;
        string path;
        int left = 0;
        int right = 0;
        backtrace(result, path, left, right, n); 
        return result;
    }
    void backtrace(vector<string> &result, string &path, int &left, int &right, const int target) {
        if (path.size() == 2*target)
            result.emplace_back(path);
        if (left < target) {
            left++;
            path += '(';
            backtrace(result, path, left, right, target);
            left--;
            path.pop_back();
        }
        if (right < left) {
            right++;
            path += ')';
            backtrace(result, path, left, right, target);
            right--;
            path.pop_back();
        }
    }
};