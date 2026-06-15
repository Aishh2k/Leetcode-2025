class RecentCounter {
public:
    queue<int> counter;
    RecentCounter() {
    }
    
    int ping(int t) {
        counter.push(t);
        while(!counter.empty()){
            if(counter.front()< t- 3000){
                counter.pop();
            }else{
                break;
            }
        }

        return(counter.size());
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */