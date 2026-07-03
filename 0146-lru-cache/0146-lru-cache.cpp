class Node{
public:
    int k;
    int v;
    Node* next;
    Node* prev;
    Node(int key, int value){
        k = key;
        v = value;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    int cap;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->next = temp;
        temp->prev = node;
        node->prev = head;
    }
    void delNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            delNode(node);
            addNode(node);
            return node->v;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->v = value;
            delNode(node);
            addNode(node);
            return;
        }else{
            if(mp.size() == cap){
                Node* del = tail->prev;
                delNode(del);
                mp.erase(del->k);
            }

            Node* node = new Node(key, value);
            addNode(node);
            mp[key] = node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */