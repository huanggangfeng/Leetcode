class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        // 讲新加入的数字放到size 小的栈里面, 如果都为空， 放到SmallHalf stack中
        if (BigHalf.size() >= SmallHalf.size()) {
            SmallHalf.push(num);
        } else
            BigHalf.push(num);
        // 第一个元素被放在了SmallHalf里面
        if (BigHalf.empty())
            return;

        // 如果BigHalf的最小值小于了SmallHalf的最大值，则需要调整，这里交换堆顶元素即可
        if (BigHalf.top() < SmallHalf.top()) {
            BigHalf.push(SmallHalf.top());
            SmallHalf.push(BigHalf.top());
            BigHalf.pop();
            SmallHalf.pop();
        }
    }
    
    double findMedian() {
        int n1 = BigHalf.size();
        int n2 = SmallHalf.size();
        if ((n1 + n2) % 2 == 0) {
            return (BigHalf.top() + SmallHalf.top()) * 1.0 / 2;
        }
        
        return n1 > n2? BigHalf.top() : SmallHalf.top();
    }
private:
    // 小顶堆来保存值较大的一半数据
    priority_queue<int, vector<int>, greater<int>> BigHalf; 
    // 大顶堆来保存值较小的一半数据
    priority_queue<int, vector<int>, less<int>> SmallHalf;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

作者：huanggangfeng
链接：https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/solution/xiang-xi-miao-shu-da-ding-dui-xiao-ding-dui-de-jie/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


    void addNum(int num) {
        bool IsBigNum = false;
        // 当前输入数字比BigHalf中的最小值要大，所以它放入BigHalf
        if (!BigHalf.empty() && num >= BigHalf.top()) {
            BigHalf.push(num);
            
            if (BigHalf.size() > (SmallHalf.size() + 1)) {
                SmallHalf.push(BigHalf.top());
                BigHalf.pop();
            }
        } else {
            SmallHalf.push(num);
            // 两个堆得大小差距超过1， SmallHalf的最大值pop出来放入BigHalf中
            if (SmallHalf.size() > (BigHalf.size()  + 1)) {
                BigHalf.push(SmallHalf.top());
                SmallHalf.pop();
            }
        }
    }

作者：huanggangfeng
链接：https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/solution/xiang-xi-miao-shu-da-ding-dui-xiao-ding-dui-de-jie/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。