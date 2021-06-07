// https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/


// dfs 就不用考虑还有回溯了
// 1. 进行分层 
// 2. 搞清楚每一层都有哪些选项
// 3. 对当前层的每个选项进行再一次dfs，

class Solution {
    vector<string> alphanum = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.empty())
            return ret;

        dfs(ret, digits, "", 0);
        return ret;
    }

    void dfs(vector<string> &ret, const string &digits, string path, int level) {
        if (path.size() == digits.size()) {
            ret.emplace_back(path);
            return;
        }
        int index = digits[level] - '0' - 2;
        string tmp = alphanum[index];
        for (int i = 0; i < tmp.size(); i++) 
            dfs(ret, digits, path + tmp[i], level + 1);
    }
};