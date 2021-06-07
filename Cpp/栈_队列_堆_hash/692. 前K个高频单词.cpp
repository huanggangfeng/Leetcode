// https://leetcode-cn.com/problems/top-k-frequent-words/

// 输入: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// 输出: ["i", "love"]
// 解析: "i" 和 "love" 为出现次数最多的两个单词，均为2次。
//     注意，按字母顺序 "i" 在 "love" 之前。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/top-k-frequent-words
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq_map;
        for (string word : words) {
            ++freq_map[word];
        }

        using freq = pair<string, int>;
        // 自己实现一个greater函数去生成一个小顶堆，但是在频率相同的时候，
        // 需要使得按照字典序排队，所以string又需要按照less的方式排序
        auto cmp = [](freq a, freq b) {
            if (a.second > b.second)
                return true;
            else if (a.second < b.second) {
                return false;
            } else if (a.second == b.second) {
                return a.first < b.first;
            }
            return false;
        };
        
        priority_queue<freq, vector<freq>, decltype(cmp)> heap(cmp);

        for (string word : words) {
            if (freq_map[word] == 0)
                continue;
            if (heap.size() < k) {
                heap.push(pair<string, int>(word, freq_map[word]));
            } else {
                heap.push(pair<string, int>(word, freq_map[word]));
                heap.pop();
            }
            freq_map[word] = 0;
        }

        int n = heap.size();
        vector<string> ret(heap.size(), "");
        while (n > 0) {
            ret[--n] = heap.top().first;
            heap.pop();
        }
        return ret;
    }
};