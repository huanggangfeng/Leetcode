// https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
// Solution： 其实就是归并排序加了一行

class Solution {
private:
    int reverseNum = 0;
public:
    int reversePairs(vector<int>& nums) {
        vector<int> tmp(nums.size(), 0);
        mergeSort(nums, 0, nums.size()-1, tmp);
        return reverseNum;
    }

    void mergeSort(vector<int>& nums, int left, int right, vector<int>& tmp) {
        if (left >= right)
            return;
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid, tmp);
        mergeSort(nums, mid + 1, right, tmp);
        merge(nums, left, mid, right, tmp);
    }

    void merge(vector<int>& nums, int left, int mid, int right, vector<int>& tmp) {
        int start1 = left;
        int start2 = mid + 1;
        int index = left;

        while (start1 <= mid && start2 <= right) {
            if (nums[start1] <= nums[start2]) {
                tmp[index++] = nums[start1++];
            } else {
                // 只需要这里加一行，当前start1对应的数字有多少个逆序对
                // [1, 3, 5, 7], [2, 4, 6, 7]
                // 1 最小，它无逆序对 start1++
                // 3 > 2， 排在后面的数字2要被插入到前面，则会跳过的逆序对个数分别为：[3, 2], [5, 2], [7,2] start2++
                // 3 < 4 无逆序对, start1++
                // 5 > 4  排在第二个数组中的数字4要被插入到前面，则会跳过的逆序对个数分别为：[5, 4], [7, 4] start2++
                // 5 < 6  无逆序对, start1++
                // 7 > 6 排在第二个数组中的数字6要被插入到前面，则会跳过的逆序对个数分别为：[7, 6] start2++
                reverseNum += mid - start1  +1;
                tmp[index++] = nums[start2++];
            }
        }

        while (start1 <= mid) {
            tmp[index++] = nums[start1++];
        }

        while (start2 <= right) {
            tmp[index++] = nums[start2++];
        }

        for (index = left; index <= right; index++) {
            nums[index] = tmp[index];
        }
    }
};