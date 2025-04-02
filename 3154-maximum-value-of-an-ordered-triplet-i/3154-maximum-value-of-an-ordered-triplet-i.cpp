class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // we calculate for all triplets
        long long maxi = LLONG_MIN;
        int n = nums.size();
        
        // n-2coz last triplet is n-3, n-2, n-1
        for(int i = 0; i < n-2; i++)
        {
            for(int j = i+1; j < n-1; j++)
            {
                for(int k = j+1; k < n; k++) 
                {
                    long long curr_sum = (long long) (nums[i] - nums[j]) * nums[k];
                    maxi = max(maxi, curr_sum);
                }
            }
        }
        
        return maxi <= 0? 0: maxi;
    }
};