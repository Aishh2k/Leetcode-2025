class Node{
    public:
        int k;
        int v;
        int f;
        Node* next;
        Node* prev;

        Node(int key, int val){
            k = key;
            v = val;
            f = 1;
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

class LFUCache {
public:
    unordered_map<int, List> freqMap;
    unordered_map<int, Node*> accessMap;
    int cap;
    int minFreq;
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    void updateFreq(Node* node){
        int freq = node->f;
        freqMap[freq].deleteNode(node);

        if(freqMap[freq].head->next == freqMap[freq].tail){
            freqMap.erase(freq);
            if(minFreq==freq){
                minFreq++;
            }
        }

        node->f++;
        freqMap[node->f].addNode(node);
    }
    
    int get(int key) {
        if(accessMap.find(key) != accessMap.end()){
            Node* node = accessMap[key];
            updateFreq(node);
            return(node->v);
        }
        return -1;
    }
    
    void put(int key, int value) {

        if(accessMap.find(key) != accessMap.end()){
            Node* node = accessMap[key];
            node->v = value;
            updateFreq(node);
            return;
        }

        if(accessMap.size()==cap){
            Node* node = freqMap[minFreq].tail->prev;
            freqMap[minFreq].deleteNode(node);
            accessMap.erase(node->k);
        }

        Node* node = new Node(key, value);
        accessMap[key] = node;
        freqMap[node->f].addNode(node);
        minFreq = 1;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */