// 实现 pow(x, n) ，即计算 x 的 n 次幂函数。

// 示例 1:

// 输入: 2.00000, 10
// 输出: 1024.00000
// 示例 2:

// 输入: 2.10000, 3
// 输出: 9.26100
// 示例 3:

// 输入: 2.00000, -2
// 输出: 0.25000
// 解释: 2-2 = 1/22 = 1/4 = 0.25

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/powx-n
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 思路：分治，每次计算一半的值，然后时间复杂度是o(NlogN)

class Solution {
public:
    // 坑之一，n可能为负数，对它取反可能越界, 用long 保存n
    double quickPow(double x, long n) {
        if (n == 0) {
            return 1.0;
        }
        double y = quickPow(x, n / 2);
        return n % 2 == 0 ? y * y : y * y * x;
    }

    double myPow(double x, int n) {
        long m = n;
        return n >= 0 ? quickPow(x, n) : 1.0 / quickPow(x, -m);
    }
};