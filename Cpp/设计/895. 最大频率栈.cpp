// 895. 最大频率栈
// 实现 FreqStack，模拟类似栈的数据结构的操作的一个类。

// FreqStack 有两个函数：

// push(int x)，将整数 x 推入栈中。
// pop()，它移除并返回栈中出现最频繁的元素。
// 如果最频繁的元素不只一个，则移除并返回最接近栈顶的元素。
 

// 示例：

// 输入：
// ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
// [[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
// 输出：[null,null,null,null,null,null,null,5,7,5,4]
// 解释：
// 执行六次 .push 操作后，栈自底向上为 [5,7,5,7,4,5]。然后：

// pop() -> 返回 5，因为 5 是出现频率最高的。
// 栈变成 [5,7,5,7,4]。

// pop() -> 返回 7，因为 5 和 7 都是频率最高的，但 7 最接近栈顶。
// 栈变成 [5,7,5,4]。

// pop() -> 返回 5 。
// 栈变成 [5,7,4]。

// pop() -> 返回 4 。
// 栈变成 [5,7]。

class FreqStack {
public:
    FreqStack() : max_freq(0) {

    }
    
    void push(int x) {
        freq_map[x]++;
        max_freq = max(max_freq, freq_map[x]);
        groups[freq_map[x]].push(x);
    }
    
    int pop() {
        int x = groups[max_freq].top();
        groups[max_freq].pop();
        freq_map[x]--;
        if(groups[max_freq].size() == 0)
            max_freq--;
        return x;
    }
private:
    // 每个元素，以及它出现的频率
    unordered_map<int, int> freq_map;
    // key是频率，value是频率为key的所有值，保存在stack中
    unordered_map<int, stack<int>> groups;
    int max_freq = 0;
};