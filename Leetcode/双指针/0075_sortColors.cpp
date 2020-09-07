// https://leetcode-cn.com/problems/sort-colors/

#include <vector>
#include <iostream>

using namespace std;

void swap(vector<int> &nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

// 三指针做法：
// index：用来遍历数组, 如果nums[index] == 1, 直接index++
// left： left的左边全是0，所以下一个如果是0，就可以和nums[left]交换， left++， index++
// right: right的右边全是2， 所以当index的位置是2的时候，nums[index] <-> nums[right], right--;

void sortColors(vector<int>& nums) {
    if (nums.empty())
        return;
    int index = 0;
    int left = 0;
    int right = nums.size() - 1;
    while (index <= right) {
        int value = nums[index];
        if (value == 0) {
            swap(nums, left, index);
            left++;
            index++; // 这里index++，因为index左边的只会是1，或者全是0，不然[2,0,2,1,1,0]的结果就会变成：
        } else if (value == 2) {
            swap(nums, index, right);
            right--;
        } else {
            index++;
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<int> test = {0, 1, 2,2,1,0,2,1};
    sortColors(test);
    for (auto i : test) 
        cout << i << "\t";
    cout << "\n";
    return 0;
}
