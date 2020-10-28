class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ret;
        if (S.empty())
            return ret;
        string path;
        dfs(S, ret, path, 0);
        return ret;
    }

    void dfs(string &S, vector<string> &ret, string path, int pos) {
        if (pos == S.size()) {
            ret.emplace_back(path);
            return;
        }
        char ch = S[pos];
        dfs(S, ret, path + ch, pos + 1);
        int offset = 'A' - 'a';
        if (ch >= 'a' && ch <= 'z') {
            ch  = ch + offset;
            dfs(S, ret, path + ch, pos + 1);
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - offset;
            dfs(S, ret, path + ch, pos + 1);
        }
    }
};