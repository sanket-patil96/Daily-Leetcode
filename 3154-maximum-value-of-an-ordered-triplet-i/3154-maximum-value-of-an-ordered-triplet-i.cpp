class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // Optimised approach: O(N) solution
        // Hint 2.
        // Use three pointers,
        // 1. One to store the largest value so far.
        // 2. One to store the largest difference so far.
        // 3. And one to store the largest triplet value so far.

        long long mxVal = -1, mxDiff = INT_MIN, mxTriplet = 0;

        for(int i = 0; i < nums.size(); i++) {
            // to ensure it can be triplet
            if(i > 1) {
                mxTriplet = max(mxDiff*nums[i], mxTriplet);
            }

            if(mxVal < nums[i])
                mxVal = nums[i];
            else 
                mxDiff = max(mxDiff, mxVal-nums[i]);
        
        }

        return mxTriplet;
    }
};