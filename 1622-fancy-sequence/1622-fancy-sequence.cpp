class Fancy {
private: 
    // To AVOID TLE: store all the operation in array as they appear, and when the index is called do that operations on that index

    // {val, add/mul = 0/1}
    vector<pair<int, int>> operations;

    // store {val, len of operations already happen so we only apply operations after that}
    vector<pair<int, int>> seq;
    int MOD = 1e9 + 7;

public:
    Fancy() {

    }
    
    void append(int val) {
        seq.push_back({val, operations.size()});
    }
    
    void addAll(int inc) {
        operations.push_back({inc, 0});
    }
    
    void multAll(int m) {
        operations.push_back({m, 1});
    }
    
    int getIndex(int idx) {
        if(idx >= seq.size())   return -1;

        // apply operation of addition and multiplication
        long long val = seq[idx].first;

        for(int i = seq[idx].second; i < operations.size(); i++) {
            if(operations[i].second == 0) 
                val += operations[i].first;
            else
                val = ((val % MOD) * operations[i].first) % MOD;
        }

        // UPDATE THE value at 'idx' so that  next time same index  appered, it don't have to do all previous operations again
        seq[idx].second = operations.size();
        seq[idx].first = val % MOD;
        
        return val % MOD;
    }  
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */