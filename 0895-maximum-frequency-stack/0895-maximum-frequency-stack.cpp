class FreqStack {
public:
    unordered_map<int, int> freq;
    int max_freq;
    unordered_map<int, vector<int>> group;

    FreqStack() {
        max_freq = 0;
    }
    
    void push(int val) {
        freq[val]++;
        group[freq[val]].push_back(val);
        max_freq = max(max_freq, freq[val]);
    }
    
    int pop() {
        int a = group[max_freq].back();
        group[max_freq].pop_back();
        freq[a]--;

        if(group[max_freq].empty()){
            max_freq--;
        }
        return a;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */