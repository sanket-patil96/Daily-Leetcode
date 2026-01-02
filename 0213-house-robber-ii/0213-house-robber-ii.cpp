class Solution {
public:
    int rob(vector<int>& nums) {
        // all houses are arranged in circle, mean the conflicting 
        // houses here are first and last one, we have to choose  any
        // one of them and exclude other house, try excluding both one by one and get maximum from it

        int n = nums.size();

        if(n == 1)
            return nums[0];

        // including first house, means don't go till last house
        int prev1 = nums[0];                    // at first index the max choice is only one that is robbing first house
        int prev2 = max(nums[1], prev1);        // at each step we want max option

        for(int i = 2; i < n-1; i++) {  // start from 2 coz we selected first house for robbing
            int robbed = nums[i] + prev1;
            prev1 = prev2;
            prev2 = max(prev2, robbed);
        }

        int maxMoney = prev2;

        // now including the last  house & excluding first one
        prev1 = 0;
        prev2 = nums[1];

        for(int i = 2; i < n; i++) {  // start from 2 coz we selected first house for robbing
            int robbed = nums[i] + prev1;
            prev1 = prev2;
            prev2 = max(prev2, robbed);
        }

        return max(maxMoney, prev2);
    }       
};