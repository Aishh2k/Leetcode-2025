class SmallestInfiniteSet {
public:
    set<int> addedBack;
    int cur = 1;
    SmallestInfiniteSet() {
        
    }
    int popSmallest() {
        if(!addedBack.empty()){
            int a  = *addedBack.begin();
            addedBack.erase(a);
            return a;
        }else{
            return(cur++);
        }
    }
    
    void addBack(int num) {
       if(num<cur){
        addedBack.insert(num);
       }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */