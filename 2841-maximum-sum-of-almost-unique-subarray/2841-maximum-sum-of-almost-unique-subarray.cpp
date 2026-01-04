class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        // similar to - 2461. Maximum Sum of Distinct Subarrays With Length K
        // we can solve it using sliding window + hashmap
        // maintain k size sliding window, and frequency of each element in that window
        // if window exceeds k then shrink window
        // if window size == k && map size is == m means this is almost unique subarray

        int n = nums.size();
        unordered_map<int, int> freq;
        int s = 0;      // starting of current subarray
        long long maxSum = 0;
        long long sum = 0;

        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
            sum += nums[i];

            // keep window size of only k, so shrink if its > k
            while(i-s+1 > k) {
                freq[nums[s]]--;
                
                // remove if freuqency become 0, so we can have idea of uniqe digits in window
                if(freq[nums[s]] == 0)
	                freq.erase(nums[s]);

                sum -= nums[s];
                s++;
            }

            
            // check the max sum, if window size is k & there are atleast k distinct elements in window
            if(i-s+1 == k && freq.size() >= m)
                maxSum = max(maxSum, sum);
        }

        return maxSum;
    }
};