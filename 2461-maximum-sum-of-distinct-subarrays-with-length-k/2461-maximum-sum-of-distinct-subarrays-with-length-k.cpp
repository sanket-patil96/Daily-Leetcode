class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        // we can solve it using sliding window + hashmap
        // keep a k size sliding window, check if every elements frequency is 1
        // if so then we can keep the sum for comparing with answer

        int n = nums.size();
        unordered_map<int, int> m;
        int s = 0;      // starting of current subarray
        long maxSum = 0;
        long sum = 0;

        for(int i = 0; i < n; i++) {
            m[nums[i]]++;
            sum += nums[i];

            // all elements should be distinct in current subarray so shrink till it happens
            while(m[nums[i]] > 1) {
                m[nums[s]]--;
                sum -= nums[s];
                s++;
            }

            // keep window size of only k, so shrink if its > k
            if(i-s+1 > k) {
                m[nums[s]]--;
                sum -= nums[s];
                s++;
            }

            // check the max sum, if window size is k
            if(i-s+1 == k)
                maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};