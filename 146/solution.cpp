#include "../solution.h"
class LRUCache{
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }

    int get(int key) {
        if(usage.find(key) == usage.end())
            return -1;
        else{
            update(key);
            return usage.find(key)->second.first;
        }
    }

    void set(int key, int value) {
        auto it = usage.find(key);
        if(it != usage.end()){
            update(key);
            it->second.first = value;
        }else{
            if((int)usage.size() >= capacity_){
                int remove_key = cache.back();
                cache.pop_back();
                usage.erase(remove_key);
            }
            cache.push_front(key);
            usage[key] = pair<int, list<int>::iterator>(value, cache.begin());
        }
    }

    void update(int key){
        auto it = usage.find(key);
        cache.push_front(key);
        cache.erase(it->second.second);
        it->second.second = cache.begin();
    }

private:
    int capacity_;
    list<int> cache;
    unordered_map<int, pair<int, list<int>::iterator> > usage;
};
