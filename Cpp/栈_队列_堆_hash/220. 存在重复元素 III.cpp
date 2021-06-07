
// 在整数数组 nums 中，是否存在两个下标 i 和 j，使得 nums [i] 和 nums [j] 的差的绝对值小于等于 t ，且满足 i 和 j 的差的绝对值也小于等于 ķ 。

// 如果存在则返回 true，不存在返回 false。

//  

// 示例 1:

// 输入: nums = [1,2,3,1], k = 3, t = 0
// 输出: true
// 示例 2:

// 输入: nums = [1,0,1,1], k = 1, t = 2
// 输出: true
// 示例 3:

// 输入: nums = [1,5,9,1,5,9], k = 2, t = 3
// 输出: false

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/contains-duplicate-iii
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// 解题思路
// 在循环index走到i的时候, 滑动窗口中只保存窗口[i-k, i)的元素, 这个时候已经满足了index i和j的差的绝对值小于等于ķ的条件,
// 所以只需要查找set中是否存在一个target value,

// target value需要满足绝对值abs(nums[i], target) <= t, 分两种情况:

// 当nums[i] > target:
// nums[i] - target <= t ===> target >= nums[i] - t
// 2. 当nums[i] < value时，
//     value - nums[i] <= t  ===> target <= nums[i] + t *
// 所以只需要判断 nums[i] - t <= target <= nums[i] + t
// STL的 set::lower_bound(x)函数返回set当中，第一个大于等于target的指针it,
// target = \it; 这个时候it还只满足(nums[i] - t) <= target, 需再判断it 是否也满足小于上限nums[i] + t;

// 代码

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.empty()){
            return false;
        }
        // 用来保存滑动窗口[i-k, i] 中的元素, 
        // 这里不用考虑重复元素, 在for中先检查是否存在符合条件的元素, 最后插入新元素nums[i], 
        // 假设set中已经有相同值得元素, 会直接return true;
        set<long> s;
        for (int i = 0; i < nums.size() ; i++) {
            // [i-k, i)的nums中查找是否有大于target的值,
            auto it = s.lower_bound((long) nums[i] - t);
            // lower_bound只满足>= nums[i] - t, 
            // 但是可能满足条件的是一个超大值, 仍需要判断是否小于upper_bound
            if (it != s.end() && *it <= (long) nums[i] + t)
                return true;

            s.emplace(nums[i]);
            if (s.size() == k + 1)
                s.erase(nums[i - k]);
        }

        return false;
    }
};

作者：huanggangfeng
链接：https://leetcode-cn.com/problems/contains-duplicate-iii/solution/hua-dong-chuang-kou-set-pei-you-xiang-xi-jie-shi-b/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。