// 运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制 。
// 实现 LRUCache 类：

// LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
// int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
// void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
//  

// 进阶：你是否可以在 O(1) 时间复杂度内完成这两种操作？

//  

// 示例：

// 输入
// ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// 输出
// [null, null, null, 1, null, -1, null, -1, 3, 4]

// 解释
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // 缓存是 {1=1}
// lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
// lRUCache.get(1);    // 返回 1
// lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
// lRUCache.get(2);    // 返回 -1 (未找到)
// lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
// lRUCache.get(1);    // 返回 -1 (未找到)
// lRUCache.get(3);    // 返回 3
// lRUCache.get(4);    // 返回 4

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/lru-cache
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


class LRUCache {
public:
    LRUCache(int capacity) {
        max_capacity = capacity;
    }
    
    int get(int key) {
        int ret = -1;
        auto it = cache_map.find(key);
        if (it != cache_map.end()) {
            ret = cache_map[key]->value;
            if (it->second != cache_list.begin()) {
                cache_list.erase(cache_map[key]);
                cache_list.push_front(Object(key, ret));
                cache_map[key] = cache_list.begin();
            }
        }
        return ret;
    }
    
    void put(int key, int value) {
        cache_list.push_front(Object(key, value));
        auto it = cache_map.find(key);
        if (it != cache_map.end()) {
            cache_list.erase(cache_map[key]);
            cache_map[key] = cache_list.begin();
        } else {
            cache_map[key] = cache_list.begin();
            if (cache_list.size() > max_capacity) {
                cache_map.erase(cache_list.rbegin()->key);
                cache_list.pop_back();
            }
        }
    }
private:
    struct Object {
        int key;
        int value;
        Object(int k, int v) : key(k), value(v) {};
    };
    int max_capacity = 0;
    map<int, list<Object>::iterator> cache_map;
    list<Object> cache_list;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */