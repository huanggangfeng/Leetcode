// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            return -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else if (nums[mid] == nums[right]) {
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
                if (nums[right] > nums[left])
                    right = mid - 1;
                else if (nums[right] < nums[left])
                    left = mid + 1;
                else if (nums[right] == nums[left])
                    right--;
            }
        }

        return nums[left];
    }
};


// 错误做法： 在整体判断过程中，因为我们返回值是left，所以如果num[mid] == nums[left]的时候不要动left，不然可能会错过答案
// [1,2]的时候 mid = 1；
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
            } else if (nums[mid] > nums[left]) {
                if (nums[left] < nums[right])
                    right = mid - 1;
                else if (nums[left] > nums[right])
                    left = mid + 1;
                else if (nums[left] == nums[right])
                    right--;
            } else if (nums[mid] == nums[left]) {
                left++; // 这里是错误的
            }
        }            
        return nums[left];
    }
};