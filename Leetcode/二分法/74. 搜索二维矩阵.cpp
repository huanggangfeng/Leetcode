// 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：

// 每行中的整数从左到右按升序排列。
// 每行的第一个整数大于前一行的最后一个整数。
//  

// 示例 1：


// 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
// 输出：true
// 示例 2：


// 输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
// 输出：false
// 示例 3：

// 输入：matrix = [], target = 0
// 输出：false
//  

// 提示：

// m == matrix.length
// n == matrix[i].length
// 0 <= m, n <= 100
// -104 <= matrix[i][j], target <= 104

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/search-a-2d-matrix
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;

        int row = matrix.size();
        int column = matrix[0].size();
        
        int top = 0;
        int bottom = row;
        while (top < bottom) {
            int mid = top + (bottom - top) / 2;
            if (matrix[mid][column - 1] == target)
                return true;
            else if (matrix[mid][column - 1] < target)
                top = mid + 1;
            else if (matrix[mid][column - 1] > target)
                bottom = mid;
        }

        if (top >= row)
            return false;
        
        int left = 0;
        int right = column;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (matrix[top][mid] == target)
                return true;
            else if (matrix[top][mid] < target) {
                left = mid + 1;
            } else 
                right = mid;
        }

        if (left >= column)
            return false;

        if (left < column && matrix[top][left] == target)
            return true;
        
        return false;
    }
};