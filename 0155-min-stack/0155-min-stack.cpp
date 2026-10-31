class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            st.push(value);
            minst.push(value);
            return;
        }

        if(value <=minst.top()){
            minst.push(value);
        }else if(value > minst.top()){
            minst.push(minst.top());
        }

        st.push(value);
        
    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
        if(!st.empty()){
            return st.top();
        }else{
            return -1;
        }
        
    }
    
    int getMin() {
        if(!minst.empty()){
            return minst.top();
        }
        return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */