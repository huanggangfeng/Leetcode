// https://leetcode-cn.com/problems/maximum-frequency-stack/
class FreqStack {
public:
    FreqStack() {

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

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */