#define TP tuple<int, int, int> 

class FreqStack {
private:
    struct cmp {
        bool operator()(TP &a, TP &b) {
            // if freq matches and first element comes later then return true as swap needed
            if(get<1>(a) == get<1>(b))
                return get<2>(a) < get<2>(b);
            else if(get<1>(a) < get<1>(b))          // if freq of first elem is less then return true as swap needed
                return true;
            else 
                return false;
        }
    };
    
    // tuple<val, freq, time>
    priority_queue<TP, vector<TP>, cmp> pq;
    unordered_map<int, int> freq;
    int timer = 0;         // near the top element identification
    
public:
    FreqStack() {}
    
    void push(int val) {
        freq[val]++;
        pq.push(make_tuple(val, freq[val], timer++));
    }
    
    int pop() {
        // reduce the frequency and remove from max heap
        int topVal = get<0>(pq.top());
        pq.pop();
        freq[topVal]--;
        return topVal;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */