// https://leetcode-cn.com/problems/simplify-path/

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        int i = 0;
        while (i < path.size()) {
            if (path[i] == '/') {
                i++;
                continue;
            }

            int count = 0;

            while (i < path.size() && path[i] == '.') {
                count++;
                i++;
            }
            
            string word;
            if (count ==1) {
                // 如果不是最后字符，那么只有下一个字符是/的时候才会处理成当前路径
                if (i < path.size() && path[i] != '/')
                    word += '.';
            } else if (count == 2) {
                // 发现两个点，它在路径的最后或者只有下一个字符是/的时候才会处理成向上一级目录
                if (i < path.size() && path[i] != '/')
                    word += string(count, '.');
                else {
                    if (!v.empty())
                        v.pop_back();
                }
            } else if (count > 2)
                word += string(count, '.');

            while (i < path.size() && path[i] != '/' && path[i] != '.' ) {
                word += path[i];
                i++;
            }
        
            if (!word.empty()) {
                v.push_back(word);
            }
        }
    
        if (v.empty())
            return "/";
        string ret;
        for (auto &e : v) {
            ret += "/";
            ret += e;
        }
        return ret;
    }
};