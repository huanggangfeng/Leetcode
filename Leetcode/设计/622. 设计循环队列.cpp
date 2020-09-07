// https://leetcode-cn.com/problems/design-circular-queue/
class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k): front(0), tail(0) {
        capability = k+1;
        data.resize(capability);
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull())
            return false;
        data[tail] = value;
        tail =(tail +1) %capability; 
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty())
            return false;
        front++;
        if (front >= capability)
            front = front % capability;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty())
            return -1;
        return data[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty())
            return -1;
        int pos = tail - 1;
        if (pos < 0)
            pos = capability - 1;
        return data[pos];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return front == tail;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (tail + 1) % capability == front;
    }
private: 
    int front;
    int tail;
    int capability;
    vector<int> data;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */