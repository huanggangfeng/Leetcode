// 在二维空间中有许多球形的气球。对于每个气球，提供的输入是水平方向上，气球直径的开始和结束坐标。由于它是水平的，所以纵坐标并不重要，因此只要知道开始和结束的横坐标就足够了。开始坐标总是小于结束坐标。

// 一支弓箭可以沿着 x 轴从不同点完全垂直地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被引爆。可以射出的弓箭的数量没有限制。 弓箭一旦被射出之后，可以无限地前进。我们想找到使得所有气球全部被引爆，所需的弓箭的最小数量。

// 给你一个数组 points ，其中 points [i] = [xstart,xend] ，返回引爆所有气球所必须射出的最小弓箭数。

//  
// 示例 1：

// 输入：points = [[10,16],[2,8],[1,6],[7,12]]
// 输出：2
// 解释：对于该样例，x = 6 可以射爆 [2,8],[1,6] 两个气球，以及 x = 11 射爆另外两个气球
// 示例 2：

// 输入：points = [[1,2],[3,4],[5,6],[7,8]]
// 输出：4
// 示例 3：

// 输入：points = [[1,2],[2,3],[3,4],[4,5]]
// 输出：2
// 示例 4：

// 输入：points = [[1,2]]
// 输出：1
// 示例 5：

// 输入：points = [[2,3],[2,3]]
// 输出：1

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


解题思路1
和其他合并区间类的题目套路一样, 都是贪心思想, 先排序, 然后遍历检查是否满足合并区间的条件
这里判断是否有交叉区间, 所以其实是计算已知区间的交集数量.
这里以[[10,16],[2,8],[1,6],[7,12]] 为例子:

先排序, 我是按区间开始位置排序, 排序后: [[1,6],[2,8],[7,12],[10,16]]
遍历计算交叉区间(待发射箭头),
待发射箭头的区间range = [1, 6], 需要的箭数量 arrows = 1;
遍历区间[2, 8], 和带发射区间[1, 6]有交集: 更新发射区域为它们的交集 range = [2, 6]
遍历区间[7, 12], 和待发射区间[2, 6]没有任何交集, 说明需要增加一个新的发射区域, 新的待发射区域range = [7, 12]
遍历区间[10,16], 和待发射区域[7, 12]有交集, 待发射区域更新为[7, 10]
返回需要待发射区间的个数
代码

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // 对于empty或只有一个区间, return;
        if (points.size() <= 1)
            return points.size();
        // 按照区间开始位置排序
        sort(points.begin(), points.end(),
            [](const vector<int> &a, const vector<int> b) {
                return a[0] == b[0] ? a[1] <= b[1] : a[0] < b[0];
            });

        int arrows = 1;
        // 初始化待发射区为[points[0][0], points[0][1]] ;
        vector<int> range = {points[0][0], points[0][1]};
        for (int i = 1; i < points.size(); i++) {
            auto curr = points[i];
            // 当前区间和待发射区间有交集, 更新交叉区间
            if (curr[0] <= range[1]) {
                range[0] = max(range[0], curr[0]);
                range[1] = min(range[1], curr[1]);
            } else {
                // 没有交集, 增加箭头数量, 将待发射区间设置为当前区间
                ++arrows;
                range[0] = curr[0];
                range[1] = curr[1];
            }
        }
        return arrows;
    }
};
解题思路2
用区间的尾部排序貌似效率会更好, 因为已经保证后面的区间右侧都是大于当前区间, 所以将发射点设置在右侧边界, 后面的区间只有左边界比它更靠左,则可以被一起处理掉
这里换个example: [[10,16],[2,5],[1,6],[7,12]] 为例子:

先排序, 按区间结束位置排序, 排序后: [[2,5],[1, 6],[7,12],[10,16]]
遍历计算交叉区间,
发射点初始化为pos = 5, 需要的箭数量 arrows = 1;
遍历区间[1, 6], 1 是小于5的, 在点5射箭可以干掉这个区间
遍历区间[7, 12], 在5的位置射箭无法打掉, 说明需要增加一个新的发射点, 新的待发射点pos = 12
遍历区间[10,16], 10 < 12那么在12位置射箭可以干掉它
返回需要射击点数量

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() <= 1) {
            return points.size();
        }
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        // 发射点设置为区间最右侧的点
        int pos = points[0][1];
        int arrows = 1;
        for (int i = 1; i < points.size(); i++) {
            auto curr = points[i];
            if (curr[0] > pos) {
                pos = curr[1];
                ++arrows;
            }
        }

        return arrows;
    }
};

作者：huanggangfeng
链接：https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/solution/he-bing-qu-jian-lei-de-ti-mu-du-shi-yi-ge-tao-lu-a/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。