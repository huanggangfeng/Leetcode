// https://leetcode-cn.com/problems/jump-game-ii/
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int max_distance = 0; // 再来一跳下次最远可达位置
        int current = 0; // 当前跳数可达的最远位置
        int jump = 0; // 当前跳数
        for (int i = 0; i < nums.size(); i++) {
            // i位置已经超出当前jump次可达的最远位置，需要再加一跳
            if (current < i) {
                jump++;
                current = max_distance;
            }
            // 再跳一次可达的最远位置
            max_distance = max(max_distance, i + nums[i]);
        }
        return jump;
    }
};

