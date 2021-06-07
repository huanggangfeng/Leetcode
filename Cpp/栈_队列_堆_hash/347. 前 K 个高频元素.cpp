// https://leetcode-cn.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 纪录每个元素出现的频率
        unordered_map<int, int> frequent;
        for (int &e : nums) {
            frequent[e]++;
        }
        // pair<num, frequent>
        using freq_pair = std::pair<int, int>;
        auto cmp = [](freq_pair left, freq_pair right){return left.second > right.second;};
        // 使用一个小顶堆来保存出现频率最高的k个元素
        priority_queue<freq_pair, vector<freq_pair>, decltype(cmp)> pq(cmp);
        for (auto &e : frequent) {
            pq.emplace(e.first, e.second);
            if (pq.size() > k)
                pq.pop();
        }

        vector<int> ret;
        while(!pq.empty()) {
            ret.emplace_back(pq.top().first);
            pq.pop();
        }
        return ret;
    }
};