#include <vector>
#include <iostream>

using namespace std;

void swap (vector<int> &nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}

int firstMissingPositive(vector<int>& nums) {
    int index = 0;
    int right = nums.size() - 1;
    //  把所有负数，以及比nums length还大的数据移到最右端，
    while (index <= right) {
        if (nums[index] <= 0 || nums[index] > nums.size()) {
            swap(nums, index, right);
            right--;
        } else
            index++;
    }

    if (right < 0)
        return 1;

    int len = right  + 1;
    index = 0;
    //  对剩余数字的数组进行扫描，index 位置对应的值应该是index+1
    while (index <= right && index < nums.size()) {
        int value = nums[index];
        if (value == index + 1) {
            index++;
        } else {
            if (value < len && nums[value -1] != value)
                swap(nums, index, value - 1);
            else {
                swap(nums, right, index);
                right--;
            }
        }
    }

    index = 0;
    // 遍历找出第一个index 位置上value不为index + 1的值
    while (index < nums.size() && nums[index] == index + 1) {
        index++;
    }
    return index  + 1;
}

int main(int argc, char const *argv[])
{
    vector<int> v1{1};
    vector<int> v2{1,2,0};
    vector<int> v3{1,2,-3,-4,7,8};
    vector<int> v4{7,8,9};
    cout << firstMissingPositive(v1) << endl;
    cout << firstMissingPositive(v2) << endl;
    cout << firstMissingPositive(v3) << endl;
    cout << firstMissingPositive(v4) << endl;
    return 0;
}