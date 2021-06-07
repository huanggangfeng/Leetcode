// https://leetcode-cn.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        if (s.empty())
            return 0;
        int total_cost = 0;
        int left = 0;
        int index = 1;
        while (index <= s.size()) {
            // cout << "1left, Index:" << left << ":" << index << "\n"; 
            if (s[left] == s[index]) {
                index++;
                continue;
            }
            // [left, index)
            if (index - left > 1) {
                // cout << "left, Index:" << left << ":" << index << "\n"; 
                int max_cost = 0;
                while (left < index) {
                    total_cost += cost[left];
                    max_cost = max(max_cost, cost[left]);
                    left++;
                }
                total_cost -= max_cost;
            } else {
                left = index;
                index++;
            }
        }
        return total_cost;
    }
};

class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int sum = 0;
        int n = s.size() - 1;
        for(int i = 0;i < n; i++)
        {
            if(s[i] == s[i+1])
            {
                sum += min(cost[i], cost[i+1]); 
                if(cost[i] > cost[i+1])
                    swap(cost[i], cost[i+1]);
            }
        }
        return sum;
    }
};