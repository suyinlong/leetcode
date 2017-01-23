class LRUCache{
struct CacheNode {
    int key, value;
    CacheNode *prev = NULL, *next = NULL;
    CacheNode(int _key, int _value) : key(_key), value(_value) {}
};

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        head = new CacheNode(0, 0);
        tail = new CacheNode(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (lruMap.find(key) == lruMap.end())
            return -1;
        CacheNode *node = lruMap[key];
        moveToHead(node);
        return node->value;
    }

    void set(int key, int value) {
        if (lruMap.find(key) == lruMap.end()) {
            CacheNode *node = new CacheNode(key, value);
            addNode(node);
            size++;
            if (size > capacity) {
                CacheNode *t = tail->prev;
                removeNode(t);
                lruMap.erase(t->key);
                delete t;
                size--;
            }
            lruMap[key] = node;
        }
        else {
            CacheNode *node = lruMap[key];
            node->value = value;
            moveToHead(node);
        }
    }

private:
    int capacity, size;
    unordered_map<int, CacheNode*> lruMap;
    CacheNode *head, *tail;

    void addNode(CacheNode *node) {
        node->prev = head;
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
    }

    void removeNode(CacheNode *node) {
        CacheNode *p = node->prev, *n = node->next;
        p->next = n;
        n->prev = p;
        node->next = NULL;
        node->prev = NULL;
    }

    void moveToHead(CacheNode *node) {
        removeNode(node);
        addNode(node);
    }
};