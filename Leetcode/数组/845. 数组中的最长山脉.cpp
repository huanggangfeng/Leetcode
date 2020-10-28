// 845. 数组中的最长山脉
// 我们把数组 A 中符合下列属性的任意连续子数组 B 称为 “山脉”：

// B.length >= 3
// 存在 0 < i < B.length - 1 使得 B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
// （注意：B 可以是 A 的任意子数组，包括整个数组 A。）

// 给出一个整数数组 A，返回最长 “山脉” 的长度。

// 如果不含有 “山脉” 则返回 0。

 

// 示例 1：

// 输入：[2,1,4,7,3,2,5]
// 输出：5
// 解释：最长的 “山脉” 是 [1,4,7,3,2]，长度为 5。
// 示例 2：

// 输入：[2,2,2]
// 输出：0
// 解释：不含 “山脉”。
// https://leetcode-cn.com/problems/longest-mountain-in-array/


class Solution {
public:
    int longestMountain(vector<int>& A) {
        if (A.empty())
            return 0;
        int ret = 0;
        vector<int> left(A.size(), 1);
        vector<int> right(A.size(), 1);
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i - 1])
                left[i] = left[i - 1] + 1;
        }

        int i = A.size() - 2;
        for (; i >= 0; i--) {
            if (A[i] > A[i + 1])
                right[i] = right[i + 1] + 1;
        }

        for (int i = 0; i < A.size(); i++) {
            // cout << "left:" << left[i] << "\t:" << right[i] << "\n"; 
            if (left[i] > 1 && right[i] > 1)
                ret = max(ret, left[i] + right[i] - 1);
        }
        return ret;
    }
};