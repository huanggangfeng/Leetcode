// 给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。

//  

// 示例：

// 输入：nums = [5,2,6,1]
// 输出：[2,1,1,0] 
// 解释：
// 5 的右侧有 2 个更小的元素 (2 和 1)
// 2 的右侧仅有 1 个更小的元素 (1)
// 6 的右侧有 1 个更小的元素 (1)
// 1 的右侧有 0 个更小的元素

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty())
            return nums;

        int n = nums.size();
        vector<int> ret(n, 0);
        vector<int> tmp{nums[n - 1]};
        for (int i = n - 2; i >= 0; i--) {
            int pos = find_insert_pos(tmp, nums[i]);
            ret[i] = pos;
            tmp.insert(tmp.begin() + pos, nums[i]);
        }
        return ret;
    }

    int find_insert_pos(vector<int> &nums, const int &target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};