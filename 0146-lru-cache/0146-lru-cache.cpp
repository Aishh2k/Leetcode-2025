class Node{
    public:
        int k;
        int v;
        Node* next;
        Node* prev;

        Node(int key, int val){
            k = key;
            v = val;
            next = NULL;
            prev = NULL;
        }
};

class List{
public:
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);

    List(){
        head->next = tail;
        tail->next = head;
    }
    void deleteNode(Node* node){
        Node* next = node->next;
        Node* prev = node->prev;
        next->prev = prev;
        prev->next = next;
    }
    void addNode(Node* node){
        Node* temp = head->next;
        node->next = temp;
        temp->prev = node;
        head->next = node;
        node->prev = head;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
    List list;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            list.deleteNode(node);
            list.addNode(node);
            return(node->v);
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            node->v = value;
            list.deleteNode(node);
            list.addNode(node);
            return;
        }

        if(mp.size()==cap){
            Node* node = list.tail->prev;
            list.deleteNode(node);
            mp.erase(node->k);
        }

        Node* node = new Node(key, value);
        mp[key] = node;
        list.addNode(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */