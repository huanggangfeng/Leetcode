// https://leetcode-cn.com/problems/ugly-number/
class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0)
            return false;
        vector<int> uglynums{2, 3, 5};

        for (auto & e: uglynums) {
            while (num % e == 0)
                num = num / e;
        }

        return num == 1;
    }
};