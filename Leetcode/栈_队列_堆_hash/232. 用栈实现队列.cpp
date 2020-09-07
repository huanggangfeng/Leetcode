// https://leetcode-cn.com/problems/implement-queue-using-stacks/
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack_in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
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
    
    /** Get the front element. */
    int peek() {
        int ret = -1;
        if (stack_out.empty()) {
            while (!stack_in.empty()) {
                stack_out.push(stack_in.top());
                stack_in.pop();
            }
        }

        if (!stack_out.empty())
            ret = stack_out.top();

        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stack_in.empty() && stack_out.empty();
    }
private:
    stack<int> stack_in;
    stack<int> stack_out;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */