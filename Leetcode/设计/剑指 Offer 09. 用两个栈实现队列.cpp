// https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
// Soluition: 使用栈in 和out同时保存所有数据，入栈比较简单，直接放入in中，出栈的时候如果out中为空，则需要从in stack中pop出来放入out栈中
class CQueue {
public:
    CQueue() {
    }
    void appendTail(int value) {
        stack_in.push(value);
    }
    
    int deleteHead() {
        int ret = -1;
        if (stack_out.empty()) {
            while (!stack_in.empty()) {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }
        if (!stack_out.empty()) {
            ret = stack_out.top();
            stack_out.pop();
        }
        return ret;
    }
    
private:
    stack<int> stack_in;
    stack<int> stack_out;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */