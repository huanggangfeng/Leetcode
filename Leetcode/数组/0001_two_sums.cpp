#include <vector>
#include <iostream>
#include <ctime>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    if (nums.empty())
        return std::vector<int>{};
    unordered_map<int, int> my_map;
    my_map[nums[0]] = 0;
    for (int i = 1; i < nums.size(); i++) {
        int num2 = target - nums[i];
        auto it = my_map.find(num2);
        if (it != my_map.end()) {
            return std::vector<int> {it->second, i};
        }
        my_map[nums[i]] = i;
    }
    return std::vector<int>{};
}

int main(int argc, char **argv) {
	vector<int> v;
	srand(time(NULL));
	for (int i = 0; i < 20; ++i) {
		v.emplace_back(rand() % 10);
	}
	vector<int> ret = twoSum(v, 10);
	for (int e : ret) {
		std::cout << e <<"\t";
	}
	std::cout << "\n";
	return 0;
}
