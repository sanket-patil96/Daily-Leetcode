class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        // sliding window approach, using map for counting the frequency in current subarray
        unordered_map<int, int> m;

        int minLen = INT_MAX;
        int n = nums.size();
        int s = 0;   // starting point of subarray
        long long sum = 0; // sum of distinct elements
        
        for(int i = 0; i < n; i++) {
            m[nums[i]]++;
            sum += nums[i];

            // remove the counting of current element if it has already counted in its first occurance
            if(m[nums[i]] > 1) 
                sum -= nums[i];
            
            // reduce size of subarray if sum exceeds k
            while(sum >= k && s <= i) {
                minLen = min(minLen, i-s+1);   // +1 coz we are getting length
                
                m[nums[s]]--;

                // if current element is appeared only once in subarray means, reduce from sum
                if(m[nums[s]] == 0)
                    sum -= nums[s];
                
                s++;
            }
        }

        return minLen == INT_MAX ? -1 : minLen;
    }
};