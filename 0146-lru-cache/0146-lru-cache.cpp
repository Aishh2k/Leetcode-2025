class Node{
    public:
    int k;
    int v;
    Node* next;
    Node* prev;

    Node(){
        k = -1;
        v = -1;
        next = NULL;
        prev = NULL;
    }
};


class LRUCache {
public:
    int c;
    unordered_map<int, Node*> mp;
    Node* head = new Node();
    Node* tail = new Node();

    LRUCache(int capacity) {
    c = capacity; 
    head->next = tail;
    tail->prev = head;
    }
    void deleteNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    void addNode(Node* node){
        Node* temp = head->next;
        node->next = temp;
        temp->prev = node;
        node->prev = head;
        head->next = node;
    }
    
    int get(int key) {
        if(mp.find(key)!= mp.end()){
            Node* node = mp[key];
            deleteNode(node);
            addNode(node);
            return(node->v);
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            node->v = value;
            deleteNode(node);
            addNode(node);
            return;
        }
        
        if(mp.size() == c){
            Node* node = tail->prev;
            deleteNode(node);
            mp.erase(node->k);
        }
        
        Node* node = new Node();
        node->k = key;
        node->v = value;
        mp[key] = node;
        addNode(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */