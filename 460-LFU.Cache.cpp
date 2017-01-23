class LFUCache {
    struct CacheNode {
        CacheNode *next = NULL, *prev = NULL;
        int key;
        int value;
        int freq;
        CacheNode(int _key, int _value) : key(_key), value(_value), freq(1) {}
    };
public:
    LFUCache(int capacity) : cap(capacity), size(0) {
        tail = NULL;
    }

    int get(int key) {
        if (lfuMap.find(key) == lfuMap.end())
            return -1;
        CacheNode *node = lfuMap[key];
        removeNode(node);
        node->freq++;
        addNode(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cap <= 0) return;
        if (lfuMap.find(key) == lfuMap.end()) {
            CacheNode *newNode = new CacheNode(key, value);
            if (size == cap) {
                CacheNode *rNode = lfuFreqMap.begin()->second;
                removeNode(rNode);
                lfuMap.erase(rNode->key);
                delete rNode;
                size--;
            }
            addNode(newNode);
            size++;
            lfuMap[key] = newNode;
        }
        else {
            CacheNode *node = lfuMap[key];
            removeNode(node);
            node->value = value;
            node->freq++;
            addNode(node);
        }
    }

private:
    int cap, size;
    CacheNode *head, *tail;
    unordered_map<int, CacheNode*> lfuMap;
    map<int, CacheNode*> lfuFreqMap;

    void addNode(CacheNode *node) {
        node->prev = NULL;
        node->next = NULL;
        if (lfuFreqMap.find(node->freq) == lfuFreqMap.end())
            lfuFreqMap[node->freq] = node;
        else {
            CacheNode *p = lfuFreqMap[node->freq];
            while (p->next) p = p->next;
            node->prev = p;
            p->next = node;
        }
    }

    void removeNode(CacheNode *node) {
        CacheNode *p = node->prev, *n = node->next;
        if (p) p->next = n;
        if (n) n->prev = p;
        if (!p && !n)
            lfuFreqMap.erase(node->freq);
        else if (!p)
            lfuFreqMap[node->freq] = n;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */