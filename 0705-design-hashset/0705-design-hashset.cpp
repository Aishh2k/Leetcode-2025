class MyHashSet {
public:
    vector<bool> k;
    MyHashSet() {
        k.resize(1000001, false);
    }
    
    void add(int key) {
        k[key] = true;
    }
    
    void remove(int key) {
        k[key] = false;
    }
    
    bool contains(int key) {
        return k[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */