class LRUCache {
public:
    class Node {
    public:
        int k;
        int v;
        Node* next;
        Node* prev;
        Node(int key, int val) {
            k = key;
            v = val;
        }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap = 0;
    unordered_map<int, Node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }
    void deleteNode(Node* node){
        Node* delPrev = node->prev;
        Node* delNext = node->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            int res = node->v;
            mp.erase(key);
            deleteNode(node);
            addNode(node);
            mp[key] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value) { 
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            mp.erase(key);
            deleteNode(node);
        }
        if(mp.size() == cap){
            mp.erase(tail->prev->k);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */