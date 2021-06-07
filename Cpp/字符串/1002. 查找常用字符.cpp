// 给定仅有小写字母组成的字符串数组 A，返回列表中的每个字符串中都显示的全部字符（包括重复字符）组成的列表。例如，如果一个字符在每个字符串中出现 3 次，但不是 4 次，则需要在最终答案中包含该字符 3 次。

// 你可以按任意顺序返回答案。
// 示例 1：
// 输入：["bella","label","roller"]
// 输出：["e","l","l"]
// 示例 2：

// 输入：["cool","lock","cook"]
// 输出：["c","o"]
 

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/find-common-characters
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        if (A.empty())
            return A;
        unordered_map<char, int> count_map;
        for (auto &ch : A[0]) {
            count_map[ch]++;
        }

        for (int i = 1; i < A.size(); i++) {
            auto it = count_map.begin();
            while (it != count_map.end()) {
                int n = count(A[i].begin(), A[i].end(), it->first);
                if (n < it->second)
                    it->second = n;
                it++;
            }
        }

        vector<string> ret;
        auto it = count_map.begin();
        while (it != count_map.end()) {
            string s;
            s = it->first;
            int n = it->second;
            while (n--) {
                ret.emplace_back(s);
            }
            it++;
        }
        return ret;
    }
};