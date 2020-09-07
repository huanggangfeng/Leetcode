// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            return -1;
        int left = 0;
        int right = nums.size() - 1;
        // 不断地缩小查找空间，保证小的值一定在下次的查询空间内
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                // [middle, right]不是升序的，索要查找的区间就是在它的里面，可以丢弃掉[left, middle]
                left = mid + 1;
            } if (nums[mid] < nums[right]) {
                // [middle, right] 是升序的，可以把(middle, right]丢掉，下次去[left, middle]中查找
                right = mid;
            } else if (nums[mid] == nums[right]) {
                // 如果相等，丢掉其中一个来缩小查找空间
                right--;
            }
        }
        return nums[left];
    }
};


class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            return -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[left]) {
                right = mid;
            } else if (nums[mid] >= nums[left]) {
                if (nums[left] < nums[right])
                    right = mid - 1;
                else if (nums[left] > nums[right])
                    left = mid + 1;
                else if (nums[left] == nums[right])
                    right--;
            }
        }            
        return nums[left];
    }
};
