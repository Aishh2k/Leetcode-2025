class MinStack {
public:
    stack<int> st;
    stack<int> minst;

    MinStack() {
        
    }
    
    void push(int value) {
        st.push(value);
        if(!minst.empty()){
            int a = minst.top();
            if(value<a){
                minst.push(value);
            }else{
                minst.push(a);
            }
        }else{
            minst.push(value);
        }
        
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
            minst.pop();
        }
    }
    
    int top() {
        if(!st.empty()){
            return(st.top());
        }else{
            return -1;
        }
    }
    
    int getMin() {
        if(!minst.empty()){
            return minst.top();
        }else{
            return -1;
        }
        
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