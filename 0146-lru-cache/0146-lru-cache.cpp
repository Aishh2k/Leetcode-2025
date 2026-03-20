struct Node {
    int k;
    int v;
    Node* next;
    Node* prev;
    Node(int key, int val) {
        k = key;
        v = val;
    }
};

class List {
public:
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    List(){
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        node->next = temp;
        temp->prev = node;
    }

    void deleteNode(Node* node) {
        Node* delPrev = node->prev;
        Node* delNext = node->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
};

class LRUCache {
public:
    int cap = 0;
    unordered_map<int, Node*> mp;
    List list;

    LRUCache(int capacity) {
        cap = capacity;
    }
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            int res = node->v;
            //mp.erase(key);
            list.deleteNode(node);
            list.addNode(node);
            //mp[key] = list.head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->v = value;
            list.deleteNode(node);
            list.addNode(node);
            return;
        }
        if (mp.size() == cap) {
            mp.erase(list.tail->prev->k);
            list.deleteNode(list.tail->prev);
        }
        list.addNode(new Node(key, value));
        mp[key] = list.head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */