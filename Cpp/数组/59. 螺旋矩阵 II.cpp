// 给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。

// 示例:

// 输入: 3
// 输出:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/spiral-matrix-ii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int index = 1;
        int limit = n * n;
        int top = 0, bottom = n;
        int left = 0, right = n;
        while (index <= limit) {
            // 从左往右
            for (int i = left; i < right; i++) {
                ret[top][i] = index++;
            }

            ++top;
            if (top >= bottom || index > limit)
                break;

            // 从上往下
            for (int i = top; i < bottom; i++) {
                ret[i][right - 1] = index++;
            }


            --right;
            if (right <= left || index > limit)
                break;

            for (int i = right - 1; i >= left; i--) {
                ret[bottom - 1][i] = index++;
            }

            --bottom;
            if (bottom <= top || index > limit)
                break;
        
            for (int i = bottom - 1; i >= top; i--) {
                ret[i][left] = index++;
            }

            ++left;
            if (left > right || index > limit)
                break;
        }

        return ret;
    }
};