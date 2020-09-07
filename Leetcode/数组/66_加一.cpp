// https://leetcode-cn.com/problems/plus-one/


//复用输入的数组，
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        vector<int> ret;
        int index = digits.size() - 1;
        digits[index] += 1;
        do {
            int value = digits[index] + carry;
            carry = value / 10;
            digits[index] = value % 10;
            --index;
        } while (carry && index >=0);

        if (carry)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};

//  创建一个新的数组来保存返回结果
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        vector<int> ret;
        int index = digits.size() - 1;
        digits[index] += 1;
        do {
            int value = digits[index] + carry;
            carry = value / 10;
            digits[index] = value % 10;
            --index;
        } while (carry && index >=0);

        if (carry)
            ret.emplace_back(1);
        else
            return digits;

        for (auto &e : digits)
            ret.emplace_back(e);

        return ret;
    }
};