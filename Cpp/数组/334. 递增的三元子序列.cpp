// https://leetcode-cn.com/problems/increasing-triplet-subsequence/

// 本题的思路非常的巧妙！
// 首先，新建两个变量 small 和 mid ，分别用来保存题目要我们求的长度为 3 的递增子序列的最小值和中间值。
// 接着，我们遍历数组，每遇到一个数字，我们将它和 small 和 mid 相比，若小于等于 small ，则替换 small；否则，若小于等于 mid，则替换 mid；否则，若大于 mid，则说明我们找到了长度为 3 的递增数组！
// 上面的求解过程中有个问题：当已经找到了长度为 2 的递增序列，这时又来了一个比 small 还小的数字，为什么可以直接替换 small 呢，这样 small 和 mid 在原数组中并不是按照索引递增的关系呀？
// Trick 就在这里了！假如当前的 small 和 mid 为 [3, 5]，这时又来了个 1。假如我们不将 small 替换为 1，那么，当下一个数字是 2，后面再接上一个 3 的时候，我们就没有办法发现这个 [1,2,3] 的递增数组了！也就是说，我们替换最小值，是为了后续能够更好地更新中间值！
// 另外，即使我们更新了 small ，这个 small 在 mid 后面，没有严格遵守递增顺序，但它隐含着的真相是，有一个比 small 大比 mid 小的前·最小值出现在 mid 之前。因此，当后续出现比 mid 大的值的时候，我们一样可以通过当前 small 和 mid 推断的确存在着长度为 3 的递增序列。 所以，这样的替换并不会干扰我们后续的计算！

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        bool  ret = false;
        if (nums.size() < 3)
            return ret;
        int samll = INT_MAX;
        int mid  = INT_MAX;
        for (auto &e : nums) {
            if (e <= samll)
                samll = e;
            else if (e <= mid)
                mid = e;
            else if (e > mid)
                return true;
        }
        return false;
    }
};

// 定义两个数组forward[i]和backward[i]，forward[i]从前向后遍历，保存[0, i]之间最小元素值，backward[i]从后向前遍历，保存[i, size - 1]间最大元素值。然后从前向后遍历，如果找到一个数满足forward[i] < nums[i] < backward[i]，则表示三元子序列存在。
// 比如：
// nums[i]: 8 3 5 1 6
// forwa[i]: 8 3 3 1 1
// backw[i]:8 6 6 6 6
