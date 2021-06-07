// https://leetcode-cn.com/problems/valid-mountain-array/


// 给定一个整数数组 A，如果它是有效的山脉数组就返回 true，否则返回 false。

// 让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组：

// A.length >= 3
// 在 0 < i < A.length - 1 条件下，存在 i 使得：
// A[0] < A[1] < ... A[i-1] < A[i]
// A[i] > A[i+1] > ... > A[A.length - 1]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/valid-mountain-array
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.empty())
            return false;
        int peak = 0;
        int i = 1;
        // 找到最高峰
        for (; i < A.size(); i++) {
            if (A[i] > A[i - 1]) {
                peak = i;
            } else
                break;
        }

        // 单调递增和单调递减都不是山峰
        if (i == A.size() || peak == 0)
            return false;


        for (; i < A.size(); i++) {
            // 如果山峰最右侧不是依次递减，则不是山峰
            if(A[i] >= A[i - 1])
                return false;
        }

        return i == A.size();   
    }
};