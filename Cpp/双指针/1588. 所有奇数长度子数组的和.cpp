// 1588. 所有奇数长度子数组的和
// 给你一个正整数数组 arr ，请你计算所有可能的奇数长度子数组的和。

// 子数组 定义为原数组中的一个连续子序列。

// 请你返回 arr 中 所有奇数长度子数组的和 。

 

// 示例 1：

// 输入：arr = [1,4,2,5,3]
// 输出：58
// 解释：所有奇数长度子数组和它们的和为：
// [1] = 1
// [4] = 4
// [2] = 2
// [5] = 5
// [3] = 3
// [1,4,2] = 7
// [4,2,5] = 11
// [2,5,3] = 10
// [1,4,2,5,3] = 15
// 我们将所有值求和得到 1 + 4 + 2 + 5 + 3 + 7 + 11 + 10 + 15 = 58
// 示例 2：

// 输入：arr = [1,2]
// 输出：3
// 解释：总共只有 2 个长度为奇数的子数组，[1] 和 [2]。它们的和为 3 。
// 示例 3：

// 输入：arr = [10,11,12]
// 输出：66

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        if (arr.empty())
            return 0;
        int ret = 0;
        // 这里vector 数量为arr.size（） + 1， 第0个为0，第i个值得前缀和保存在sum[i+1]
        vector<int> sum(arr.size() + 1, 0);
        for (int i = 0; i < arr.size(); i++) {
            sum[i + 1] = sum[i] + arr[i];
        }

        // 开始位置不断向右移动
        for (int start = 0; start < arr.size(); start++) {
            // 对于每个开始位置，计算接下来奇数个连续数值的累加和
            for (int len = 1; len <= arr.size(); len += 2) {
                int end = start + len;
                if (end > arr.size())
                    break;
                else
                    ret += sum[end] - sum[start];
            }
        }
        return ret;
    }
};

作者：huanggangfeng
链接：https://leetcode-cn.com/problems/sum-of-all-odd-length-subarrays/solution/shuang-zhi-zhen-li-yong-qian-zhui-he-de-si-xiang-q/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。