// https://leetcode-cn.com/problems/implement-stack-using-queues/
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        while (!queue_in.empty()) {
            queue_out.push(queue_in.front());
            queue_in.pop();
        }
        queue_in.push(x);
        while (!queue_out.empty()) {
            queue_in.push(queue_out.front());
            queue_out.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ret = queue_in.front();
        queue_in.pop();
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        return queue_in.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return queue_in.empty() && queue_out.empty();
    }
private:
    queue<int> queue_in;
    queue<int> queue_out;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */