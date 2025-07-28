class MyQueue {
    stack<int> s1;
public:
    MyQueue() {
        // using single stack:
        // as we want front element of queue on top of stack, we need to insert element in stack 
        // in such way that every new element will be inserted at bottom of stack so first element will remain on top
        // we can do this using recursion: insert every element at bottom
    }
    
    void push(int x) {
        if(s1.empty()) {
            // now stack is empty so new element will be at bottom
            s1.push(x);
            return;
        }
        
        int val = s1.top();
        s1.pop();
        
        push(x);
        
        // now push last taken element while returning, so they will remain as it is
        s1.push(val);        
    }
    
    int pop() {
        int val = s1.top();
        s1.pop();
        return val;
    }
    
    int peek() {
         return s1.top();   
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */