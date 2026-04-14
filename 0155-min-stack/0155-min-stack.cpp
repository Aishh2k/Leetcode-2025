class MinStack {
public:
    MinStack() {
        
    }

    stack<int> st;
    stack<int> minst;
    
    void push(int val) {
        if(st.empty()){
            minst.push(val);
        }else{
            int a = minst.top();
            if(val<a){
                minst.push(val);
            }else{
                minst.push(a);
            }
        }
        st.push(val);
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
            minst.pop();
        }
    }
    
    int top() {
        return(st.top());
    }
    
    int getMin() {
        return(minst.top());
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */