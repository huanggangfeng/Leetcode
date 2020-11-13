// 假设有打乱顺序的一群人站成一个队列。 每个人由一个整数对(h, k)表示，其中h是这个人的身高，k是排在这个人前面且身高大于或等于h的人数。 编写一个算法来重建这个队列。

// 注意：
// 总人数少于1100人。

// 示例

// 输入:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

// 输出:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/queue-reconstruction-by-height
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


// 核心思路非常简单：

// 先排身高更高的，这是要防止后排入人员影响先排入人员位置
// 每次排入新人员[h,k]时，已处于队列的人身高都>=h，所以新排入位置就是people[k]
// 有了这两个思路代码实现就非常简单了

// 先将people按照身高降序排序，又由于每次插入的位置是k，所以相同身高需要按k升序排序，否则插入位置会越界
// 由于后续需要频繁使用insert()操作，建议使用list作为中间容器
// 循环地从头读取people，根据people[i][1]也就是k,插入list，注意list的迭代器不支持随机访问，需要使用advance()找到应插入位置
// 将完成所有插入操作的list重建为vector返回

// 作者：lammmm
// 链接：https://leetcode-cn.com/problems/queue-reconstruction-by-height/solution/406-gen-ju-shen-gao-zhong-jian-dui-lie-8xing-dai-m/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 排序
        sort(people.begin(), people.end(),
                [](const vector<int>& lhs, const vector<int>& rhs)
                 {return lhs[0] == rhs[0] ? lhs[1] <= rhs[1] : lhs[0] > rhs[0];});
        int len = people.size();
        list<vector<int>> tmp;
        // 循环插入
        for(int i = 0; i < len; ++i){
            auto pos = tmp.begin();
            advance(pos, people[i][1]);
            tmp.insert(pos, people[i]);
        }
        // 重建vector返回
        return vector<vector<int>>(tmp.begin(), tmp.end());
    }
};