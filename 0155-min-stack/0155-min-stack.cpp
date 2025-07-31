class MinStack {
    stack<int> minSt, st;
public:
    MinStack() {
        // we will maintain 2 stacks, 1 for normal stack operations and 2nd for the minstack operation
        // if the current value is lesser than minStack top then push to minstack else ignore
        // getMin: top of minStack
        // pop(): normal pop from stack 1, and if its similar to top of minStack then pop from that also
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty() || minSt.top() >= val)
            minSt.push(val);
    }
    
    void pop() {
        int val = st.top();
        st.pop();

        if(val == minSt.top())
            minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
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