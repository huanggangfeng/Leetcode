// https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/

class Solution {
public:
    vector<int> printNumbers(int n) {
       vector<int> ret;
        if (n <= 0)
            return ret;

        for (int i = 1; i <= n; i++) {
            string path;
            dfs(ret, path, i);
        }
        return ret;
    }

    void dfs(vector<int> &ret, string path, int len) {
        if (path.size() == len) {
            ret.emplace_back(atoi(path.c_str()));
            return;
        }
        int i = 0;
        // 第一次从1开始，后面都是从0开始
        if (path.empty())
            i = 1;
        for (; i <= 9; i++) {
            dfs(ret, path + to_string(i), len);
        }
    }
};