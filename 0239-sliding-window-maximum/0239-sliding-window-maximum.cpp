class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // all operations of deque takes O(1) time
        // every elem is pushed and popped 1 times each so over time complexity is O(n)
        // T/C: O(n)    S/C: O(k)
        vector<int> maxi;
        deque<int> dq;
        int n = nums.size();

        // we procese first k elements
        for(int i = 0; i < k; i++)
        {
            // store indexes in dq so we can easily remove index which is our of k size window

            // we pop unneccessory elements from deque, 
            // ex: 4 1 2 5 6   here we first store 4 1 2 and after that when we see 
            // greater elem of right side(5) then left side elems becomes useless as 5 is also
            // part of the window that 4 1 2 has, they never become max for any window after 5
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            
            // after removing all unnecessory elems push current elem in queue rear(back)
            dq.push_back(i);
        }

        // maximum always remian on front coz we remove front if we see any greater elem in
        // same size window so that greater element comes on front
        maxi.push_back(nums[dq.front()]);

        // now we process next window elements
        for(int i = k; i < n; i++)
        {
            // we first remove elem which is out of window of size 'k'
            // i-k is index which is out of window of 'k' for current window
            // front always containing less index than other elements in dq
            if(!dq.empty() && dq.front() <= i-k)
                dq.pop_front();

            // now we again do same thing before inserting new index of item
            while(!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            
            // push index of current new item in window at end of dq
            dq.push_back(i);

            // push maximum for current window
            maxi.push_back(nums[dq.front()]);
        }

        return maxi;
    }
};