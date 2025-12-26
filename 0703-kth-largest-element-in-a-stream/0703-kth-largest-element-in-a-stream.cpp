class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int kl = 0;
    KthLargest(int k, vector<int>& nums) {
        kl = k;
        for(int i: nums){
            pq.push(i);
            if(pq.size()> k){
                pq.pop();
            }
        }

    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>kl){
            pq.pop();
        }

        return(pq.top()); 
    }
};
