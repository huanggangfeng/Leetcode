// https://leetcode-cn.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // little ended heap
        auto cmp = [](int left, int right) { return left > right; };
        std::priority_queue<int, std::vector<int>, decltype(cmp)> heap(cmp);

        int i = 0;
        while(i < k) {
            heap.push(nums[i]);
            i++;
        }

        while (i < nums.size()) {
            if (nums[i] > heap.top()) {
                heap.pop();
                heap.push(nums[i]);
            }
            i++;
        }

        return heap.top();
    }
};