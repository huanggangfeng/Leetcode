// 给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。

// 换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。

// 以数组形式返回答案。

//  

// 示例 1：

// 输入：nums = [8,1,2,2,3]
// 输出：[4,0,1,1,3]
// 解释： 
// 对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。 
// 对于 nums[1]=1 不存在比它小的数字。
// 对于 nums[2]=2 存在一个比它小的数字：（1）。 
// 对于 nums[3]=2 存在一个比它小的数字：（1）。 
// 对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
// 示例 2：

// 输入：nums = [6,5,4,8]
// 输出：[2,1,0,3]
// 示例 3：

// 输入：nums = [7,7,7,7]
// 输出：[0,0,0,0]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/how-many-numbers-are-smaller-than-the-current-number
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        if (nums.empty())
            return nums;

        vector<int> data(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            data[i] = nums[i];
        }

        sort(data.begin(), data.end());
        unordered_map<int, int> pos_map;
        pos_map[data[0]] = 0;
        for (int i = 1; i < data.size(); i++) {
            if (pos_map.find(data[i]) == pos_map.end()) {
                pos_map[data[i]] = i;
            }
        }

        int i = 0;
        for (int num : nums) {
            data[i++] = pos_map[num];
        }    
        return data;
    }
};


// 计数排序
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        if (nums.empty())
            return nums;
        map<int, int> count;
        for (int num : nums) {
            ++count[num];
        }

        auto it = count.begin();
        int sum = 0;
        int tmp = 0;
        while (it != count.end()) {
            tmp = it->second;
            it->second = sum;
            sum += tmp;
            it++;
        }

        vector<int> ret(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            ret[i] = count[nums[i]];
        }

        return ret;
    }
};