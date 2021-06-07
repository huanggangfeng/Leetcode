#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

void merge(vector<int> &nums, int start, int mid, int end, vector<int> &tmp) {
    int left = start;
    int right = mid + 1;
    int index = start;
    while (left <= mid && right <= end) {
        if (nums[left] <= nums[right])
            tmp[index++] = nums[left++];
        else
            tmp[index++] = nums[right++];
    }

    while (left <= mid) {
        tmp[index++] = nums[left++];
    }

    while (right <= end) {
        tmp[index++] = nums[right++];
    }

    for (index = start; index <= end; index++) {
        nums[index] = tmp[index];
    }
}

void merge_sort(vector<int> &nums, int start, int end, vector<int> &tmp) {
    if (start >= end)
        return;
    int mid = start + (end - start) / 2; 
    merge_sort(nums, start, mid, tmp);
    merge_sort(nums, mid + 1, end, tmp);
    merge(nums, start, mid, end, tmp);
}

void print_vec(const std::vector<int> &nums) {
    for (auto &e : nums)
        cout << "\t" << e;
    cout << "\n";
}

void sort_2(std::vector<int> &nums) {
    vector<int> tmp(nums.size(), 0);
    merge_sort(nums, 0, nums.size() - 1, tmp);
}


int main(int argc, char const *argv[])
{
    std::vector<int> nums(10, 0);
    srand(time(NULL));
    for (auto &e : nums) {
        e = rand() % 100;
    }

    print_vec(nums);
    sort_2(nums);
    print_vec(nums);
    return 0;
}


