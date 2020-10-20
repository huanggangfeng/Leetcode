// 给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

// 示例 1：

// 输入：[-4,-1,0,3,10]
// 输出：[0,1,9,16,100]
// 示例 2：

// 输入：[-7,-3,2,3,11]
// 输出：[4,9,9,49,121]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/squares-of-a-sorted-array
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 同样地，我们可以使用两个指针分别指向位置 00 和 n-1n−1，每次比较两个指针对应的数，选择较大的那个逆序放入答案并移动指针。
// 这种方法无需处理某一指针移动至边界的情况，读者可以仔细思考其精髓所在


class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        if (A.empty())
            return A;
        vector<int> ret(A.size(), 0);
        int left = 0;
        int right = A.size() - 1;
        int index = A.size() - 1;
        while (left <= right) {
            int val1 = A[left] * A[left];
            int val2 = A[right] * A[right];
            if (val1 > val2) {
                ret[index--] = val1;
                left++;
            } else {
                ret[index--] = val2;
                right--;
            }
        }

        return ret;
    }
};