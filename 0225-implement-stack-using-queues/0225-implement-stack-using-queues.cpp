// use q1 as stack, and q2 for temperory putting the queue element into it so we can insert new element on front of q1 then appen the previous values  from q2
class MyStack {
queue<int> q1, q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        // insert all elemes of q1 into q2
        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // insert current new element in q1 so accessible at front like top of stack
        q1.push(x);

        // now fill the previous elements of q1 from q2
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
         // pop the front of q1 which is simulating top of stack
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