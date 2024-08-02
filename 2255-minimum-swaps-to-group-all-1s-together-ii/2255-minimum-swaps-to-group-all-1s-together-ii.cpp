class Solution {
public:
    int minSwaps(vector<int>& nums) {
        // first count ones in array
        // our answer will be the all gaps between ones so count the gap that are zero's in each window
        // we create a window for total 1's size
        // to avoid the circular property, we append nums to itself

        int cntOnes = 0;
        for(auto num: nums) 
            if(num)
                cntOnes++;

        if(cntOnes == nums.size()) 
            return 0;
        
        int n = nums.size();;
        for(int i = 0; i < n; i++)
            nums.push_back(nums[i]);
        
        
        // now calculate first window
        int swaps = INT_MAX;
        int sum = 0;
        for(int i = 0; i < cntOnes; i++) 
            sum += nums[i];
        swaps = min(swaps, cntOnes-sum);

        // now calculate for remianing windows
        for(int i = cntOnes; i < n*2; i++) {
            // add the current value and remove the out of window value
            sum += nums[i] - nums[i - cntOnes];
            swaps = min(swaps, cntOnes-sum);
        }

        return swaps;
    }
};