// https://leetcode-cn.com/problems/daily-temperatures/submissions/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        stack<int> s;
        vector<int> ret(n, 0);
        for (int i = 0; i < n; i++) {
            //把栈里面温度比当前低的全部弹出, 赋予等待天数
            while(!s.empty() && T[i] > T[s.top()]) {
                int previousIndex = s.top();
                ret[previousIndex] = i - previousIndex;
                s.pop();
            }
            s.push(i);
        }
        return ret;
    }
};
