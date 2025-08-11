class FreqStack {
private: 

    struct compare {
        bool operator()(const pair<int, pair<int, int>>& a,
                        const pair<int, pair<int, int>>& b) const {
            // First compare by frequency (max frequency first)
            if (a.first != b.first)
                return a.first < b.first; // max heap for freq

            // If frequency matches, compare by insertTime (max insertTime first)
            return a.second.first < b.second.first;
        }
    };

    // {freq, insertTime, value}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare> pq;
    unordered_map<int, int> freq;
    int time;
    
public:

    FreqStack() {
        time = 0;
    }
    
    void push(int val) {
        freq[val]++;
        pq.push({freq[val], {time++, val}});
    }

    int pop() {
        // remove the top frequenct value from heap & also decrease its frequency
        int top = pq.top().second.second;
        freq[top]--;
        pq.pop();

        return top;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */