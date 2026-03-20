struct Node {
    int k;
    int v;
    int f;

    Node* next;
    Node* prev;
    Node(int key, int value){
        k = key;
        v = value;
        f = 1;
    }
};

class List{
    public:
        Node* head = new Node(-1,-1);
        Node* tail = new Node(-1,-1);

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

class LFUCache {
public:
    int minFreq;
    int maxCapacity;
    unordered_map<int, Node*> mp; // access map
    unordered_map<int, List> freqMap; // freq map

    LFUCache(int capacity) {
        maxCapacity = capacity;
        minFreq = 0;
    }

    void updateFreq(Node* node){
        int freq = node->f;
        freqMap[freq].deleteNode(node);

        if(freqMap[freq].head->next == freqMap[freq].tail){
            freqMap.erase(freq);
            if(minFreq == freq){
                minFreq++;
            }
        }

        node->f++;
        freqMap[++freq].addNode(node);
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* node = mp[key];
            updateFreq(node);
            return node->v;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){ // already exists
            Node* node = mp[key];
            node->v = value;
            updateFreq(node);
            return;
        }

        if(mp.size() == maxCapacity){ // evict LFU
            Node* node = freqMap[minFreq].tail;
            mp.erase(node->prev->k);
            freqMap[minFreq].deleteNode(node->prev);
        }

        Node* node = new Node(key, value);
        mp[key] = node;
        freqMap[1].addNode(node);
        minFreq = 1;  
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */