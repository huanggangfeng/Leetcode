// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

// 注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。

//  

// 示例 1：

// 输入：s = "ADOBECODEBANC", t = "ABC"
// 输出："BANC"
// 示例 2：

// 输入：s = "a", t = "a"
// 输出："a"
//  

// 提示：

// 1 <= s.length, t.length <= 105
// s 和 t 由英文字母组成

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/minimum-window-substring
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.size() < t.size())
            return "";
        unordered_map<char, int> targetFreq;
        unordered_map<char, int> sourceFreq;

        for (char &ch: t) {
            ++targetFreq[ch];
        }

        int left = 0;
        int right = 0;
        for (; right < t.size() - 1; right++) {
            ++sourceFreq[s[right]];
        }

        int answer = -1;
        int len = INT_MAX;
         while (right < s.size()) {
            ++sourceFreq[s[right]];
            ++right;
            while (IsCovered(sourceFreq, targetFreq)) {
                if (right - left < len) {
                    len = right - left;
                    answer = left;
                }
                --sourceFreq[s[left]];
                ++left;
            }
        };

        return answer == -1 ? "" : s.substr(answer, len);
    }

    bool IsCovered(unordered_map<char, int> &src, unordered_map<char, int> &target) {
        auto it = target.begin();
        while (it != target.end()) {
            if (src.find(it->first) == src.end() || src[it->first] < it->second)
                return false;
            ++it;
        }
        return true;
    }
};