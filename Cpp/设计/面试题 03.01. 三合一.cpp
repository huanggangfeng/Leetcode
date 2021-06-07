// 三合一。描述如何只用一个数组来实现三个栈。

// 你应该实现push(stackNum, value)、pop(stackNum)、isEmpty(stackNum)、peek(stackNum)方法。stackNum表示栈下标，value表示压入的值。

// 构造函数会传入一个stackSize参数，代表每个栈的大小。

// 示例1:

//  输入：
// ["TripleInOne", "push", "push", "pop", "pop", "pop", "isEmpty"]
// [[1], [0, 1], [0, 2], [0], [0], [0], [0]]
//  输出：
// [null, null, null, 1, -1, -1, true]
// 说明：当栈为空时`pop, peek`返回-1，当栈满时`push`不压入元素。
// 示例2:

//  输入：
// ["TripleInOne", "push", "push", "push", "pop", "pop", "pop", "peek"]
// [[2], [0, 1], [0, 2], [0, 3], [0], [0], [0], [0]]
//  输出：
// [null, null, null, null, 2, 1, -1, -1]

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/three-in-one-lcci
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

class TripleInOne {
public:
    TripleInOne(int stackSize) {
        _size = stackSize;
        nums.resize(stackSize * 3);
        tops.resize(3);
        tops[0] = 0;
        tops[1] = stackSize;
        tops[2] = 2 *stackSize;
    }
    
    void push(int stackNum, int value) {
        int top = tops[stackNum];
        if (top < (stackNum + 1)* _size) {
            nums[top++] = value;
            tops[stackNum]++;
        }
    }
    
    int pop(int stackNum) {
        int ret = -1;
        int top = tops[stackNum];
        if (top > stackNum * _size) {
            ret = nums[top - 1];
            --tops[stackNum];
        }
        return ret;
    }
    
    int peek(int stackNum) {
        int ret = -1;
        int top = tops[stackNum];
        if (tops[stackNum] > stackNum * _size) {
            ret = nums[top - 1];
        }
        return ret;
    }
    
    bool isEmpty(int stackNum) {
        return tops[stackNum] == stackNum * _size;
    }
private:
    int _size = 0;
    vector<int> nums;
    vector<int> tops;
    vector<int> bottoms;
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */