
// 假设按照升序排序的数组在预先未知的某个点上进行了旋转。

// ( 例如，数组 [0,0,1,2,2,5,6] 可能变为 [2,5,6,0,0,1,2] )。

// 编写一个函数来判断给定的目标值是否存在于数组中。若存在返回 true，否则返回 false。

// 示例 1:

// 输入: nums = [2,5,6,0,0,1,2], target = 0
// 输出: true
// 示例 2:

// 输入: nums = [2,5,6,0,0,1,2], target = 3
// 输出: false
// 进阶:

// 这是 搜索旋转排序数组 的延伸题目，本题中的 nums  可能包含重复元素。
// 这会影响到程序的时间复杂度吗？会有怎样的影响，为什么？

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 解题思路
// 这题难点在于怎么判断不符合条件的一半, 如果不能扔掉一半, 起码要不断地缩小空间. 每次拿到一个mid后, 如果它不等于target, 那么它可以将整个区间分为左侧[left, mid) 和右侧(mid, right), 而且整个两个区间值总有一个是有序的, 我们只有判断target是不是在有序的区间内, 是的话就可以把另外一半扔掉, 不在这有序的区间内的话, 就扔掉有序的这一半.

// 每一次二分后: 如果target已经找到, 可以直接返回,
// 否则剩余区间可以分为2个部分[left, mid) 和 (mid, right);
// 情况1: nums[mid] > nums[left] : 暗示[left, mid) 有序的, (mid, right)则是螺旋的
// 判断target 是不是在[left, mid), 如果是则right = mid, 不在这个区间的话, 那么肯定在(mid, right), left = mid + 1;
// 情况2: nums[mid] < nums[left] : 暗示(mid, right) 是有序的
// 判断target 是不是在(mid, right) 中, 如果是则left = mid +1, 不在这个区间的话, 那么肯定在[left, mid), right = mid;
// 情况2: nums[mid] == nums[left], 无法区分,但是由于nums[mid] != target, 可以left++;

// 代码

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty())
            return false;
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return true;
            
            if (nums[mid] > nums[left]) { // mid左边的数组[left, mid)是有序的
                // target 就在[left, mid)中
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < nums[left]) {// mid 右边(mid, right)是有序的
                // target 就在(mid, right)中
                if (target > nums[mid] && target <= nums[right - 1])
                    left = mid + 1;
                else
                    right = mid;
            } else if (nums[mid] == nums[left]) {
                    left++;
            }
        }

        return false;
    }
};
// 用nums[right] 判断也是一样的, 每次扔掉一半, 就是不能扔掉一半, 也起码缩小一点空间


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty())
            return false;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return true;
            
            if (nums[mid] > nums[right]) { // mid左边的数组是有序的
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < nums[right]) {// mid 右边数组是有序的
                if (target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            } else if (nums[mid] == nums[right]) {
                    right--;
            }
        }

        return false;
    }
};

作者：huanggangfeng
链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/solution/er-fen-fa-jing-sui-jiu-shi-mei-ci-nu-li-reng-diao-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。