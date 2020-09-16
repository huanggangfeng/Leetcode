
// https://leetcode-cn.com/problems/jian-sheng-zi-lcof/submissions/
// 经典动态规划问题
// 

class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[i]= max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};

class Solution {
public:
    int cuttingRope(int n) {
        if (n < 0)
            return 0;
        if(n == 2)
            return 1;
        if(n == 3)
            return 2;
        vector<int> dp(n + 1, 0);

        for (int i = 2; i <= n; i++) {
            for(int j = 1; j < i; j++){
                int tmp = max(j * (i - j), j * dp[i - j]);
                dp[i] = max(dp[i], tmp);
            }
        }
        return dp[n];
    }
};

// 数学方法：
class Solution {
public:
    int cuttingRope(int n) {
        if (n == 2 || n == 3)
            return n - 1;
        int constant = 1000000007;
        long res = 1;
        while (n > 4) {
            //如果n大于4，我们不停的让他减去3
            n = n - 3;
            //计算每段的乘积
            res = res * 3 % constant;
        }
        return (int) ((res * n) % constant);
    }
};
