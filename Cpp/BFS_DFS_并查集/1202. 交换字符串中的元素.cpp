// https://leetcode-cn.com/problems/smallest-string-with-swaps/
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        union_find UF(s.size());
        for (auto &pair : pairs) {
            UF.merge(pair[0], pair[1]);
        }

        // 根据root分成不同group, vector 保存同group所拥有的slot
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < s.size(); i++) {
            groups[UF.find(i)].push_back(i);
        }

        string ret = s;

        for (auto it = groups.begin(); it != groups.end(); it++) {
            vector<int> indexs = it->second;
            string tmp;
            // 取出每个group拥有的所有字符
            for (auto &index : indexs) {
                tmp += s[index];
            }
            // 同一个group的字符字典序排序
            sort(tmp.begin(), tmp.end());

            int i = 0;
            // 排好序的字符放到当前group拥有的slot里去
            for (auto &index : indexs) {
                ret[index] = tmp[i++];
            }
        }        
        return ret;
    }

private:
    struct union_find {
        vector<int> parent;
        union_find(int size) {
            parent.resize(size);
            for (int i = 0; i < size; i++) {
                parent[i] = i;
            }
        }

        int find (int x) {
            int root = x;
            while (root != parent[root]) {
                root = parent[root];
            }

            // 所有节点都指向root结点，这样树只有2层
            while (root != x) {
                int tmp = parent[x];
                parent[x] = root;
                x = tmp;
            }
            return root;
        }

        void merge(int x, int y) {
            parent[find(x)] = parent[find(y)];
        }
    };
};