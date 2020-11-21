// 给定两个字符串 s 和 t，它们只包含小写字母。

// 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

// 请找出在 t 中被添加的字母。

//  

// 示例 1：

// 输入：s = "abcd", t = "abcde"
// 输出："e"
// 解释：'e' 是那个被添加的字母。
// 示例 2：

// 输入：s = "", t = "y"
// 输出："y"
// 示例 3：

// 输入：s = "a", t = "aa"
// 输出："a"
// 示例 4：

// 输入：s = "ae", t = "aea"
// 输出："a"

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/find-the-difference
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnt(26, 0);
        for (char &ch : s) {
            ++cnt[ch - 'a'];
        }

        for (char &ch : t) {
            --cnt[ch - 'a'];
        }

        char ret = 'a';
        for (int i = 0; i < 26; i++) {
            if (cnt[i] < 0) {
                ret += i;
                break;
            }
        }
        return ret;
    }
};


class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans = 0;
        for (char ch : t) ans += ch;
        for (char ch : s) ans -= ch;
        return (char)ans;
    }
};