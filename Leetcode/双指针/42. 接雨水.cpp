// https://leetcode-cn.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2)
            return 0;
        int left_edge[height.size()];
        int right_edge[height.size()];
        int largest_index = 0;
        left_edge[0] = 0;
        for (int i = 1; i< height.size(); i++) {
            if (height[i] > height[largest_index])
                largest_index = i;
            left_edge[i] = height[largest_index];
        }

        right_edge[height.size() - 1] = height.size() - 1;
        largest_index =  height.size() - 1;
        for (int i = height.size() - 1; i >= 0; i--) {
            if (height[i] > height[largest_index]) {
                largest_index = i;
            }
            right_edge[i] = height[largest_index];
        }
        int ret = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            
            int tmp = 0;
            if (left_edge[i] > right_edge[i])
                tmp = right_edge[i] - height[i];
            else
                tmp = left_edge[i] - height[i];
            // cout << "Index " << i << " "<< left_edge[i] << ":" << right_edge[i] << "\t water:";
            // cout << tmp << endl;
            ret += tmp;
        }
        return ret;
    }
};
