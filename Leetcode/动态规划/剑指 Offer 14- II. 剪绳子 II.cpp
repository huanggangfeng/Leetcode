// https://leetcode-cn.com/problems/jian-sheng-zi-ii-lcof/

// 和剪绳子1一模一样，唯一区别就是这里区间变大，需要考虑越界问题
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