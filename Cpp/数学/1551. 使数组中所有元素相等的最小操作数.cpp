// 存在一个长度为 n 的数组 arr ，其中 arr[i] = (2 * i) + 1 （ 0 <= i < n ）。

// 一次操作中，你可以选出两个下标，记作 x 和 y （ 0 <= x, y < n ）并使 arr[x] 减去 1 、arr[y] 加上 1 （即 arr[x] -=1 且 arr[y] += 1 ）。最终的目标是使数组中的所有元素都 相等 。题目测试用例将会 保证 ：在执行若干步操作后，数组中的所有元素最终可以全部相等。

// 给你一个整数 n，即数组的长度。请你返回使数组 arr 中所有元素相等所需的 最小操作数 。

//  

// 示例 1：

// 输入：n = 3
// 输出：2
// 解释：arr = [1, 3, 5]
// 第一次操作选出 x = 2 和 y = 0，使数组变为 [2, 3, 4]
// 第二次操作继续选出 x = 2 和 y = 0，数组将会变成 [3, 3, 3]
// 示例 2：

// 输入：n = 6
// 输出：9

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/minimum-operations-to-make-array-equal
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 平均为n，1

class Solution {
public:
    int minOperations(int n) {
        int ret = 0, avg = n;
        for (int i = 0; i < n; i++) {
            int x = 2 * i + 1;
            if (x > n) {
                ret += x - n;
            }
        }
        return ret;
    }
};


class Solution {
public:
    int minOperations(int n) {
        return n * n / 4;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/minimum-operations-to-make-array-equal/solution/shi-shu-zu-zhong-suo-you-yuan-su-xiang-deng-de-z-4/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。