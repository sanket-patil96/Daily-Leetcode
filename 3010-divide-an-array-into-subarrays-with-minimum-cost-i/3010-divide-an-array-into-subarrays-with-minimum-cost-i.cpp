class Solution {
public:
    int minimumCost(vector<int>& nums) {
        
        // optimised: t/c: O(N)
        // as we only concerned about the first elements of each subarray
        // we don't even require 2 loops
        // 1st element will always be part of our sum (for 1st element of 1st subarray)
        // then we need to find 2 smallest elements in array
        // sum up and return 

        int n = nums.size();
        int ans = nums[0];

        int min1 = INT_MAX;
        int min2 = INT_MAX;
        for(int i = 1; i < n; i++) {
            if(nums[i] < min1) {
                min2 = min1;        // update 2nd smallest to smallest before, updating smallest
                min1 = nums[i];
            }
            else if(nums[i] < min2)
                min2 = nums[i];
        }

        return ans + min1+ min2;
    }
};