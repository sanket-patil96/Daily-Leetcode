// approach using single queue
// while pushing the elements into queue, push the current value, then reverse queue except last added element using
// a loop pop the front and add it to last of queue
// then other pop & top will be same as stack for queue front
class MyStack {
queue<int> q1;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);

        for(int i = 0; i < q1.size()-1; i++) {
            int val = q1.front();
            q1.pop();
            q1.push(val);
        }
    }
    
    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */