// https://leetcode-cn.com/problems/insert-delete-getrandom-o1/
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool ret = false;
        if (index_map.find(val) == index_map.end()) {
            data.emplace_back(val);
            index_map[val] = data.size() - 1;
            ret = true;
        }
        return ret;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool ret = false;
        auto it = index_map.find(val);
        if (it != index_map.end()) {
            data[it->second] = data[data.size() -1]; 
            index_map[data[data.size() -1]] = it->second;     
            data.pop_back();
            index_map.erase(val);
            ret = true;
        }
        return ret;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        if (data.empty())
            return -1;
        return data[rand() % data.size()];
    }
private:
    vector<int> data;
    unordered_map<int, int> index_map;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */