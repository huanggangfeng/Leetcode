#include <vector>
#include <iostream>
#include <ctime>

using namespace std;

void quick_sort(vector<int> &nums, int start, int end) {
    if (start >= end)
        return;
	int left = start;
	int right = end;
	int pivot = nums[start + (end - start)	/ 2];
	while (left <= right) {
		while (left < right && nums[left] < pivot)
			left++;
		
		while (left < right && nums[right] > pivot)
			right++;

		if (left <= right) {
			int tmp = nums[left];
			nums[left] = nums[right];
			nums[right] = tmp;
			left++;
			right--;
		}
	}

	quick_sort(nums, start, right);
	quick_sort(nums, left, end);
}

void print_vec(const std::vector<int> &nums) {
    for (auto &e : nums)
        cout << "\t" << e;
    cout << "\n";
}

void sort_2(std::vector<int> &nums) {
    quick_sort(nums, 0, nums.size() - 1);
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


