// https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/


// 思路： 维护一个双端队列max_dequeue，它里面的元素是单调的，总是从大到小的排列
// push操作:当一个元素入队的时候有3种情况:
//  1. 新来的元素比之前的最大值都大，则可以把max_queue 清空了, 因为如果再没有新来元素,它永远都会是最大元素，用该元素作为max_queue的队首
//  2. 新来的元素比队尾都小，push_back到max——queue的队尾
//  3. 新来的元素比max——queue的队首小，但是比队尾大，从后向前把比它小的pop出去，然后再把该元素push——back

// 2. Pop的时候，如果发现当前data_queue将要弹出的元素是最大元素，则max_queue也需要把队首弹出
// 3. 
class MaxQueue {
public:
    MaxQueue() {

    }
    
    int max_value() {
        if (!max_queue.empty())
            return max_queue.front();
        return -1;
    }
    
    void push_back(int value) {
        data_queue.push(value);
        if (max_queue.empty())
            max_queue.push_back(value);
        else if (value > max_queue.front()) {
            max_queue.clear();
            max_queue.push_back(value);
        } else {
		    while (max_queue.back() < value) {
                max_queue.pop_back();
            }
		    max_queue.push_back(value);
        }
    }

    int pop_front() {
        if (data_queue.empty())
            return -1;
        int ret =data_queue.front();
        data_queue.pop();

        if (ret == max_queue.front())
            max_queue.pop_front();
        return ret;
    }
private:
    queue<int> data_queue;
    deque<int> max_queue;
};