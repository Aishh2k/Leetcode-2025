class MedianFinder {
public:
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!max.empty() && num > max.top()){ // should the number go to the smaller half or larger half
            min.push(num); 
        }else{
            max.push(num);
        }

        // next step is balancing the DS
        if(max.size() > min.size() +1){
            min.push(max.top());
            max.pop();
        }else if(min.size() > max.size() +1){
            max.push(min.top());
            min.pop();
        }
    }

    double findMedian() {
        if(max.size() == min.size()){
            return ((double) (max.top() + min.top())/2);
        }else if(max.size() > min.size()){
            return(max.top());
        }else{
            return min.top();
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */