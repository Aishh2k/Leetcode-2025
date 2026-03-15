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
class LFUCache {
public:
    int minFreq;
    int maxCapacity;
    unordered_map<int, Node*> mp; // access map
    unordered_map<int, list<Node*>> freqMap; // freq map

    LFUCache(int capacity) {
        maxCapacity = capacity;
        minFreq = 0;
    }

    void updateFreq(Node* node){
        int freq = node->f;
        freqMap[freq].remove(node);

        if(freqMap[freq].empty()){
            freqMap.erase(freq);
            if(minFreq == freq){
                minFreq++;
            }
        }

        node->f++;
        freqMap[++freq].push_front(node);
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
            Node* node = freqMap[minFreq].back();
            mp.erase(node->k);
            freqMap[minFreq].pop_back();
        }

        Node* node = new Node(key, value);
        mp[key] = node;
        freqMap[1].push_front(node);
        minFreq = 1;  
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */