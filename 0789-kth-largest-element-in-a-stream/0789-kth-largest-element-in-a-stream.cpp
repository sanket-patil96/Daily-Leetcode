class KthLargest {
public:
    // we use min Heap which will give kth largest each time if top is < curr elem then we pop
    // top & push current elem in min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;      // used to use in add method

    KthLargest(int k, vector<int>& nums) {
        // KthLargest* obj = new KthLargest(k, nums);
        this->k = k;

        // first fill k elems in min-heap then update the top for more than k elems
        for(auto i: nums) {
            if(pq.size() < k)
                pq.push(i);

            else if(pq.top() < i) {
                pq.pop();
                pq.push(i);
            }
        }
    }

    int add(int val) {
        if(pq.size() < k)
            pq.push(val);

        // now check if val > heap top
        else if(val > pq.top())
        {
            pq.pop();
            pq.push(val);
        }

        // now return top
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */