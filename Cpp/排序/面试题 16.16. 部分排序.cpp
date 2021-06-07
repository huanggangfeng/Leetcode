// https://leetcode-cn.com/problems/sub-sort-lcci/

// 给定一个整数数组，编写一个函数，找出索引m和n，只要将索引区间[m,n]的元素排好序，整个数组就是有序的。注意：n-m尽量最小，也就是说，找出符合条件的最短序列。函数返回值为[m,n]，若不存在这样的m和n（例如整个数组是有序的），请返回[-1,-1]。

// 示例：

// 输入： [1,2,4,7,10,11,7,12,6,7,16,18,19]
// 输出： [3,9]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/sub-sort-lcci
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 思路：两遍扫
// 1. 第一遍从左往右扫，如果有序，应该是递增的，每个值都要比前面的最大值大，找下去，找到最后一个比前面最大值小的index，它就是不顺序的最右侧
// 2. 第二遍从右往左扫，如果有序，应该是递减的，每个值都要比后面的最小值小，找下去，找到最后一个比后面最小值都大的index, 它就是不顺序的最左侧

class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        vector<int> ret{-1, -1};
        if (array.size() <= 1)
            return ret;
        int last = 0;
        int max = array[0];
        for (int i = 1; i < array.size(); i++) {
            if (array[i] < max) {
                last = i;
            } else
                max = array[i];
        }
      

        int min = array[array.size() - 1];
        int first = array.size() - 1;
        for (int i = array.size() - 1; i >= 0; i--) {
            if (array[i] > min) {
                first = i;
            } else
                min = array[i];
        }
        if (first < last) {
            ret[0]= first;
            ret[1] = last;
        }
        return ret;
    }
};