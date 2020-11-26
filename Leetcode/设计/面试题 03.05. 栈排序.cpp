// 栈排序。 编写程序，对栈进行排序使最小元素位于栈顶。最多只能使用一个其他的临时栈存放数据，但不得将元素复制到别的数据结构（如数组）中。该栈支持如下操作：push、pop、peek 和 isEmpty。当栈为空时，peek 返回 -1。

// 示例1:

//  输入：
// ["SortedStack", "push", "push", "peek", "pop", "peek"]
// [[], [1], [2], [], [], []]
//  输出：
// [null,null,null,1,null,2]
// 示例2:

//  输入： 
// ["SortedStack", "pop", "pop", "push", "pop", "isEmpty"]
// [[], [], [], [1], [], []]
//  输出：
// [null,null,null,null,null,true]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/sort-of-stacks-lcci
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class SortedStack {
public:
    SortedStack() {
    }
    
    void push(int val) {
        while (!data_stack.empty() && val > data_stack.top()) {
            helper_stack.push(data_stack.top());
            data_stack.pop();
        }

        data_stack.push(val);
        while (!helper_stack.empty()) {
            data_stack.push(helper_stack.top());
            helper_stack.pop();
        }
    }
    
    void pop() {
        if (!data_stack.empty())
            data_stack.pop();
    }
    
    int peek() {
        int ret = -1;
        if (!data_stack.empty())
            ret = data_stack.top();
        return ret;
    }
    
    bool isEmpty() {
        return data_stack.empty();
    }
private:
    stack<int> data_stack;
    stack<int> helper_stack;
};

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack* obj = new SortedStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->isEmpty();
 */