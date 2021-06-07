// https://leetcode-cn.com/problems/reverse-integer/submissions/

class Solution {
public:
    int reverse(int x) {
        int negative = 1;
        if (x < 0) {
            negative = -1;
            x = x * -1;
        }
        int ret = 0;
        while (x > 0) {
            ret = ret*10 + x%10;   
            x /= 10; 
        }
        return negative*ret;
    }
};

// 考虑溢出情况
class Solution {
public:
    int reverse(int x) {
      int ret = 0;
      while (x) {
        int pop = x % 10;
        if (ret > INT_MAX/10 || (ret == INT_MAX / 10 && pop > 7))
            return 0;
        if (ret < INT_MIN/10 || (ret == INT_MIN / 10 && pop < -8))
            return 0;
        ret = ret * 10 + pop;
        x = x/10;  
      }
      return ret;
    }
};