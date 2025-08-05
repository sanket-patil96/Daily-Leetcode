class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // approach3: overall time = O(k + (n-k) * logK) this is better using Min Heap
        // using max Heap time = O(N + KlogN)
        // 1. build min heap of first k elems
        // 2. traverse from k+1'th element
        //    compare current elem with top of min heap, 
        //          if: top is greater then ignore 
        //          else: pop top item and push current elem in heap
        //          using this heap will contain k max elems at any point 
        // 3. at last heap will contain kth greater elements at top(coz its min heap)
        
        // time: O(K)
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.begin()+k);
        
        // time: O(N-k * logK), N-K for traversing & logk for pushing & extracting
        for(int i = k; i < nums.size(); i++)
        {
            if(pq.top() < nums[i])
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        return pq.top();
    }
};