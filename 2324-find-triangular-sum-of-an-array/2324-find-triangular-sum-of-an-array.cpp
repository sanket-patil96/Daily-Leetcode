class Solution {
public:
    int triangularSum(vector<int>& nums) {
        // simply go as the process says
        
        int n = nums.size();
        
        while(n > 1) {
            vector<int> temp;

            for(int i = 0; i < n-1; i++) 
                temp.push_back((nums[i]+nums[i+1]) % 10);
            
            nums = temp;
            n--;            // at each iteration nums size get reduced 
        }

        return nums[0];
    }
};