// https://leetcode-cn.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1)
            return 0;
        int left = 0;
        int right = height.size() - 1;
        int ret = 0;
        while (left < right) {
            int tmp = right - left;
            if (height[left] < height[right]) {
                 tmp *= height[left];
                 left++;
            } else {
                tmp *= height[right];
                right--;
            }
            ret = ret > tmp ? ret: tmp;
        }
        return ret;
    }
};