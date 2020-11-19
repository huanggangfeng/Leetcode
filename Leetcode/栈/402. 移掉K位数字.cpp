// 对于两个相同长度的数字序列，最左边不同的数字决定了这两个数字的大小，例如，对于 A = 1axxxA=1axxx，B = 1bxxxB=1bxxx，如果 a > ba>b 则 A > BA>B。

// 基于此，我们可以知道，若要使得剩下的数字最小，需要保证靠前的数字尽可能小。

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/remove-k-digits/solution/yi-diao-kwei-shu-zi-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> s;
        for (char ch : num) {
            while (!s.empty() && ch < s.back() && k) {
                s.pop_back();
                --k;
            }
            s.push_back(ch);
        }

        for (; k > 0; --k) {
            s.pop_back();
        }

        string ans = "";
        bool isLeadingZero = true;
        for (auto& digit: s) {
            // 第一个非零数字前的0都不要输出
            if (isLeadingZero && digit == '0') {
                continue;
            }
            isLeadingZero = false;
            ans += digit;
        }
        return ans == "" ? "0" : ans;
    }
};