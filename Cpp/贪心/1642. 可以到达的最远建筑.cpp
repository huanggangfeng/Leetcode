
// DFS的思路, 超时了
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        if (heights.size() <= 1)
            return 0;
        return helper(heights, bricks, ladders, 0, heights.size());
    }

    int helper(vector<int>& heights, int bricks, int ladders, int pos, const int end) {
        ++pos;
        // 如果楼的高度依次都是递减, 可不需要砖块或者梯子
        while (pos < end && heights[pos] <= heights[pos - 1]) {
            ++pos;
        }

        // 已经爬到头了
        if (pos == end) {
            return end - 1;
        }

        // 当前可以到达的楼
        int ret = pos - 1;

        // 从pos - 1 到pos 的高度差, 
        int offset = heights[pos] - heights[pos - 1];
        // 如果砖块足够,可以选择使用砖块
        if (bricks >= offset)
            ret = max(ret, helper(heights, bricks - offset, ladders, pos, end));
        // 如果有梯子,也可以选择使用梯子
        if (ladders > 0)
            ret = max(ret, helper(heights, bricks, ladders - 1, pos, end));
        return ret;
    }
};

// 优先级队列的思路
思路与算法

在移动的过程中，我们会需要若干次需要使用砖块或者梯子的情况。假设当前我们需要移动到下一建筑物，但必须使用 11 架梯子或者 \Delta hΔh 个砖块，那么我们如何抉择是使用梯子还是砖块呢？

我们可以用贪心的思路来想这个问题。「梯子」相当于一次性的无限量砖块，那么我们一定是把梯子用在刀刃上。也就是说，如果我们有 ll 架梯子，那么我们会在 \Delta hΔh 最大的那 ll 次使用梯子，而在剩余的情况下使用砖块。

这样一来，我们就可以得到正确的算法了：我们使用优先队列实时维护不超过 ll 个最大的 \Delta hΔh，这些就是使用梯子的地方。对于剩余的 \Delta hΔh，我们需要使用砖块，因此需要对它们进行累加，如果某一时刻这个累加值超过了砖块的数目 bb，那么我们就再也无法移动了。

作者：zerotrac2
链接：https://leetcode-cn.com/problems/furthest-building-you-can-reach/solution/ke-yi-dao-da-de-zui-yuan-jian-zhu-by-zerotrac2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        if (heights.size() <= 1)
            return 0;
        priority_queue<int, vector<int>, greater<int>> heap;
        int i = 1;
        for (; i < heights.size(); i++) {
            if (heights[i] > heights[i - 1]) {
                int offset = heights[i] - heights[i -1];
                heap.emplace(offset);
                if (heap.size() > ladders) {
                    int cnt = heap.top();
                    if (cnt <= bricks) {
                        bricks -= cnt;
                        heap.pop();
                    } else {
                        break;
                    }
                }
            }
        }

        return i - 1;
    }
};
