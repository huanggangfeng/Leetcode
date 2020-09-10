// https://leetcode-cn.com/problems/merge-intervals/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 1)
            return intervals;
        // 先排序，安装区间左侧值排序
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ret;
        for (int i = 0; i < intervals.size(); i++) {
            int L = intervals[i][0];
            int R = intervals[i][1];
            // 当前区间的left 都要比merged 区间里最右测值还大，所以直接插入
            if (ret.empty() || ret.back()[1] < L)
                ret.push_back(intervals[i]);
            else {
                // 当前区间的left 都要比merged 区间里最右测值小， 这里隐含条件是当前区间的左侧比merged 区间左侧要大，所以max(R, ret.back()[1]) 为right bound
                ret.back()[1] = max(ret.back()[1], R);
            }

        }
        return ret;
    }
};

