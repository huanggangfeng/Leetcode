// https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                return vector<int> {left+1, right+1};
            } else if (numbers[left] + numbers[right] < target)
                left++;
            else if (numbers[left] + numbers[right] > target)
                right--;
        }

        return vector<int> {-1, -1};
    }
};