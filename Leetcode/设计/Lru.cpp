class LRUCache {
public:
    LRUCache(int capacity) {
        max_capacity =capacity;
    }

    int get(int key) {
        //lock_guard<mutex> lock(mtx);
        if (cache_map.find(key) != cache_map.end()) {
            if (cache_map[key] != object_list.begin()) {
                object_list.push_front(*cache_map[key]);
                object_list.erase(cache_map[key]);
                cache_map[key] = object_list.begin();
            }
            return cache_map[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        struct object_node node(key, value); 
        //lock_guard<mutex> lock(mtx);
        if (cache_map.find(key) != cache_map.end()) {
            object_list.erase(cache_map[key]);
        }
        object_list.push_front(node);
        cache_map[key] = object_list.begin();
        if (cache_map.size() > max_capacity) {
            auto k = object_list.rbegin()->key;
            if (cache_map.find(k) != cache_map.end()) {
                cache_map.erase(k);
            }
            object_list.pop_back();
        }
    }
private:
    struct object_node {
        int key;
        int value;
        object_node(int key, int value) : key(key), value(value){};
    };
    unordered_map<int, list<object_node>::iterator> cache_map;
    list<object_node> object_list;
    //mutex mtx;
    int max_capacity;
};