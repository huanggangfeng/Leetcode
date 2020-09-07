// https://leetcode-cn.com/submissions/detail/91747507/
class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers.empty())
            return 0;
        int previous = numbers[0];
        bool found = false;
        int i = 1;
        for (; i < numbers.size(); i++) {
            if (numbers[i] < previous) {
                found = true;
                break;
            }
            else
                previous = numbers[i];
        }
        return found ? numbers[i] : numbers[0];
    }

};