// 187. 重复的DNA序列
// 所有 DNA 都由一系列缩写为 'A'，'C'，'G' 和 'T' 的核苷酸组成，例如："ACGAATTCCG"。在研究 DNA 时，识别 DNA 中的重复序列有时会对研究非常有帮助。

// 编写一个函数来找出所有目标子串，目标子串的长度为 10，且在 DNA 字符串 s 中出现次数超过一次。

 

// 示例 1：

// 输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
// 输出：["AAAAACCCCC","CCCCCAAAAA"]
// 示例 2：

// 输入：s = "AAAAAAAAAAAAA"
// 输出：["AAAAAAAAAA"]
 

// 提示：

// 0 <= s.length <= 105
// s[i] 为 'A'、'C'、'G' 或 'T'

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        if (s.size() <= 10)
            return ret;
        unordered_map<string, int> substrs;
        int len = s.size() - 10;
        for (int i = 0; i <= len; i++) {
            substrs[s.substr(i, 10)]++;
        }

        auto it = substrs.begin();
        while (it != substrs.end()) {
            if (it->second > 1)
                ret.push_back(it->first);
            it++;
        }
        return ret;
    }
};