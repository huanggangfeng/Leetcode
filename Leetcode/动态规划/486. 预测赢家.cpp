// https://leetcode-cn.com/problems/predict-the-winner/

// 假设我是玩家1，对手是玩家2
// 每一个格子是我作为一个玩家，设身处地地假设我本人或我的对手面对着区间(i,j)，作出最好的选择后能领先的最多分数。

// 当我面对着(i,j)区间，我作为一个玩家每次只能选择i位置或j位置。
// 如果我选择了i，那么我的对手将会获得(i+1,j)格子内的分数；
// 而如果我选择了j，我的对手将获得(i,j-1)格子内的分数。
// 而这(i+1,j)格子和(i,j-1)格子内有多少分数，是我站在对手的角度为他思考而最多能领先分数。

// 只要我站在格子(i,j)在做判断，此时的我的身份可能是我自己，也可能是我在为想象的对手考虑！

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int length = nums.size();
        int dp[length][length];
        for (int i = 0; i < length; i++) {
            dp[i][i] = nums[i];
        }
        for (int i = length - 2; i >= 0; i--) {
            for (int j = i + 1; j < length; j++) {
                dp[i][j] = max(nums[i] - dp[i+1][j], nums[j] - dp[i][j-1]);
            }
        }
        return dp[0][length-1] >= 0;
    }
};

// 上述代码中使用了二维数组 dp。分析状态转移方程可以看到，dp[i][j] 的值只和 dp[i + 1][j] 以及dp[i][j−1] 有关，即在计算 dp 的第  行的值时，只需要使用到dp 的第 i行和第 i+1 i+1 行的值，因此可以使用一维数组代替二维数组，对空间进行优化。

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int length = nums.size();
        int dp[length];
        for (int i = 0; i < length; i++) {
            dp[i] = nums[i];
        }
        for (int i = length - 2; i >= 0; i--) {
            for (int j = i + 1; j < length; j++) {
                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
            }
        }
        return dp[length - 1] >= 0;
    }
};