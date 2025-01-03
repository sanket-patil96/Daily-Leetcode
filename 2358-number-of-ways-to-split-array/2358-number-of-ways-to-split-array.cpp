class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // simply get prefix sum from left & right both
        // and for each i check leftSum >= rightSum, if yes then ans++

        int n = nums.size();
        vector<long> preSumLeft(n);         // to handle larger addition use long

        preSumLeft[0] = nums[0];
        for(int i = 1; i < n; i++) 
            preSumLeft[i] = preSumLeft[i-1]+nums[i];

        int ans = 0;
        for(int i = 0; i < n-1; i++) 
            // get right sum by using leftSums last value - current value of prefixSum
            if(preSumLeft[i] >= (preSumLeft[n-1]-preSumLeft[i]))
                ans++;
        

        return ans;
    }
};