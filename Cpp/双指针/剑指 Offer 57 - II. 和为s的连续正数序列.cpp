// https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int left = 1; 
        int right = 2;
        vector<vector<int>> results;
        vector<int> result;
        for (; left < right; ) {
            int sum = (left + right) * (right - left + 1) / 2;
            if (sum == target) {
                result.clear();
                for (int i = left; i <= right; i++)
                    result.emplace_back(i);
                results.emplace_back(result);
                left++;
            } else if (sum < target) {
                right++;
            } else {
                left++;
            }
        }
        return results;
    }
};