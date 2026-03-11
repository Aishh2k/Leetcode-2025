class LRUCache {
public:
    class LRU { // doubly linked list
    public:
        int val;
        int k;
        LRU* next;
        LRU* prev;
        LRU(int key, int value) {
            k = key;
            val = value;
        }
    };
    unordered_map<int, LRU*> mp; // key -> node in DLL
    LRU* head = new LRU(-1,-1);
    LRU* tail = new LRU(-1,-1);
    int cap = 0;

    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head;
        cap = capacity;
    }
    void removeNode(LRU* node){
        LRU* delPrev = node->prev;
        LRU* delNext = node->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    void addHead(LRU* node){
        LRU* n = head->next;
        node->next = n;
        n->prev = node;
        node->prev = head;
        head->next = node;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        LRU* node = mp[key];
        removeNode(node);
        addHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if(cap ==0){
            return;
        }
        if(mp.find(key) != mp.end()){
            LRU* node = mp[key];
            removeNode(node);
            node->val = value;
            addHead(node);
            return;
        }else if (mp.size() == cap) {
            LRU* node = tail -> prev;
            removeNode(node);
            mp.erase(node->k);
        }

        LRU* newNode = new LRU(key, value);
        addHead(newNode);
        mp[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */