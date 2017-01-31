class AllOne {
    struct KV {
        int value;
        unordered_set<string> keys;
    };
public:
    /** Initialize your data structure here. */
    AllOne() {
    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (kmap.find(key) == kmap.end())
            kmap[key] = kvlist.insert(kvlist.begin(), {0, {key}});

        auto bucket = kmap[key], next = bucket;
        next++;
        if (next == kvlist.end() || next->value > bucket->value + 1)
            next = kvlist.insert(next, {bucket->value + 1, {}});
        next->keys.insert(key);
        kmap[key] = next;

        bucket->keys.erase(key);
        if (bucket->keys.empty())
            kvlist.erase(bucket);
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (kmap.find(key) == kmap.end())
            return;

        auto bucket = kmap[key], prev = bucket;
        if (bucket != kvlist.begin())
            prev--;
        kmap.erase(key);
        if (bucket->value > 1) {
            if (bucket == kvlist.begin() || prev->value < bucket->value - 1)
                prev = kvlist.insert(bucket, {bucket->value - 1, {}});
            prev->keys.insert(key);
            kmap[key] = prev;
        }

        bucket->keys.erase(key);
        if (bucket->keys.empty())
            kvlist.erase(bucket);
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return kvlist.empty() ? "" : *(kvlist.rbegin()->keys.begin());
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return kvlist.empty() ? "" : *(kvlist.begin()->keys.begin());
    }
private:
    list<KV> kvlist;
    unordered_map<string, list<KV>::iterator> kmap; // key -> list<KV>::iterator
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */