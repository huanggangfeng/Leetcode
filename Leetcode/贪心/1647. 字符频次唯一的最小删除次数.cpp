// 如果字符串 s 中 不存在 两个不同字符 频次 相同的情况，就称 s 是 优质字符串 。

// 给你一个字符串 s，返回使 s 成为 优质字符串 需要删除的 最小 字符数。

// 字符串中字符的 频次 是该字符在字符串中的出现次数。例如，在字符串 "aab" 中，'a' 的频次是 2，而 'b' 的频次是 1 。

// 示例 1：

// 输入：s = "aab"
// 输出：0
// 解释：s 已经是优质字符串。
// 示例 2：

// 输入：s = "aaabbbcc"
// 输出：2
// 解释：可以删除两个 'b' , 得到优质字符串 "aaabcc" 。
// 另一种方式是删除一个 'b' 和一个 'c' ，得到优质字符串 "aaabbc" 。
// 示例 3：

// 输入：s = "ceabaacb"
// 输出：2
// 解释：可以删除两个 'c' 得到优质字符串 "eabaab" 。
// 注意，只需要关注结果字符串中仍然存在的字符。（即，频次为 0 的字符会忽略不计。）

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/minimum-deletions-to-make-character-frequencies-unique
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

/*
一、题目简化总体思路：
s = "ffffggggaaabbbcc" --> {a:3},{b:3},{c:2},{f:4},{g:4} --> 3,3,2,4,4 --> 3,1,2,4,0 / 3,2,1,4,0
首先,对字符串做数据统计;
然后,可以发现题目转化为,重复数字的去重;（与字母是没有关系的）
最后,去重的策略;

二、去重策略：
input : 3,3,2,4,4
result: 3,2,1,4,0

arr={3,3,2,4,4}
dir={}
for(auto i:arr){
    将每一个数arr[i]依次放入新的字典dir;
    如果在dir不存在，则插入;
    如果在dir存在，则将数字减一继续判断在dir是否存在;
    直到这个arr[i]为0为止，并统计减一的步数。
}

*/

class Solution {
public:
    int minDeletions(string str) {
        unordered_map<char, int> freq;
        for (char &ch: str) {
            ++freq[ch];
        }

        unordered_set<int> s;
        int ret = 0;
        auto it = freq.begin(); 
        while (it != freq.end()) {
            int cnt = it->second;
            if (s.find(cnt) == s.end()) {
                s.emplace(cnt);
            } else {
                do {
                    ++ret;
                    --cnt;
                } while (s.find(cnt) != s.end());

                if (cnt != 0) {
                    s.emplace(cnt);
                }
            }
            ++it;
        }
        return ret;
    }
};