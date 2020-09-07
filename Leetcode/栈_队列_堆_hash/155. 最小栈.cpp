// https://leetcode-cn.com/problems/min-stack/

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if (data_stack.empty()) {
            min_stack.push(x);
            data_stack.push(x);
        } else {
            if (x < min_stack.top()) {
                min_stack.push(x);
                data_stack.push(x);
            } else {
                min_stack.push(min_stack.top());
                data_stack.push(x);
            }
        }
    }
    
    void pop() {
        if (!data_stack.empty()) {
            data_stack.pop();
            min_stack.pop();
        }
    }
    
    int top() {
        if (!data_stack.empty())
            return data_stack.top();
        else 
            return -1;
    }
    
    int getMin() {
        if (!min_stack.empty())
            return min_stack.top();
        else 
            return -1;
    }
private: 
    stack<int> data_stack;
    stack<int> min_stack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */