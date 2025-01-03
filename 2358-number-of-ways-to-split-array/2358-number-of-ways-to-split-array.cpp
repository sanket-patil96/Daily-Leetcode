class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // simply get prefix sum from left & right both
        // and for each i check leftSum >= rightSum, if yes then ans++

        int n = nums.size();
        vector<long> preSumRight(n), preSumLeft(n);         // to handle larger addition use long

        preSumLeft[0] = nums[0];
        for(int i = 1; i < n; i++) 
            preSumLeft[i] = preSumLeft[i-1]+nums[i];

        preSumRight[n-1] = 0;
        for(int i = n-2; i >= 0; i--) 
            preSumRight[i] = preSumRight[i+1]+nums[i+1];

        int ans = 0;
        for(int i = 0; i < n-1; i++) 
            if(preSumLeft[i] >= preSumRight[i])
                ans++;
        

        return ans;
    }
};