class Node {
public:
    int k;
    int v;
    Node* next;
    Node* prev;

    Node(){
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    int cap;
    Node* head = new Node();
    Node* tail = new Node();
    unordered_map<int, Node*> mp;

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

    void deleteNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            deleteNode(node);
            addNode(node);
            return node->v;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            deleteNode(node);
            node->v = value;
            mp.erase(key);
            addNode(node);
            mp[key] = node;
        }

        if(mp.size() == cap){
            Node* node = tail->prev;
            deleteNode(node);
            mp.erase(node->k);
        }

        Node* node = new Node();
        node->k = key;
        node->v = value;
        addNode(node);
        mp[key] = node; 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */