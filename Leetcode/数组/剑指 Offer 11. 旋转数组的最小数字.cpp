// https://leetcode-cn.com/submissions/detail/91747507/


class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers.empty())
            return INT_MIN;
        int left = 0;
        int right = numbers.size() - 1;

        if (numbers[left] < numbers[right])
            return numbers[left];

        while (left < right) {
            int mid = left + (right - left) / 2;
             // mid 比最右侧的值大，说明mid在最小值的左侧
            if (numbers[mid] > numbers[right]) {
                left = mid + 1;
            } else if (numbers[mid] < numbers[right]) {
                // mid 比最右侧的值小， 可以丢弃区间(mid, right]
                right = mid;
            } else {
                right--;
            }
        }
        return numbers[left];
    }
};


class Solution {
public:
    int minArray(vector<int>& nums) {
        if (nums.empty())
            return -1;
        int left = 0;
        int right = nums.size() - 1;
        if (nums[right] > nums[left])
            return nums[left];

        while (left < right) {
            int mid = left + (right - left) / 2;
            // [left, mid] 有序, 可以全部丢掉
            if (nums[mid] > nums[0]) {
                left = mid + 1;
            } else if (nums[mid] < nums[0]) {
                // [left, mid] 是目标区间， (mid, right]丢掉
                right = mid;
            } else {
                // mid 和 nums[left] 相等，
                if (nums[left] <= nums[right]) {
                    // 目标在[mid, right) 中间
                    right--;
                } else { // 目标在(left, mid] 中间
                    left++;
                }
            }   
        }            
        return nums[left];
    }
};


class Solution {
public:
    int minArray(vector<int>& nums) {
        if (nums.empty())
            return -1;
        int left = 0;
        int right = nums.size() - 1;
        int n = right;
        if (nums[right] > nums[left])
            return nums[left];

        while (left < right) {
            int mid = left + (right - left) / 2;
            // 目标在mid右侧，左侧可以全部丢掉
            if (nums[mid] > nums[n]) {
                left = mid + 1;
            } else if (nums[mid] < nums[n]) {
                // (mid, right] 都可以丢掉
                right = mid;
            } else {
                // mid 和 nums[left] 相等，
                if (nums[left] <= nums[right]) {
                    // 目标在[mid, right) 中间
                    right--;
                } else { // 目标在(left, mid] 中间
                    left++;
                }
            }   
        }            
        return nums[left];
    }
};