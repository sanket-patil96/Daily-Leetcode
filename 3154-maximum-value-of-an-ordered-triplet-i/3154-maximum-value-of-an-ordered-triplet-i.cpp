class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        // Optimised approach: O(N) solution
        // Hint 2.
        // Use three pointers,
        // 1. One to store the largest value so far.
        // 2. One to store the largest difference so far.
        // 3. And one to store the largest triplet value so far.

        long long mxTriplet = 0;
        int mxVal = -1, mxDiff = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            mxTriplet = max((long long) mxDiff*nums[i], mxTriplet);
            mxVal = max(mxVal, nums[i]);
            mxDiff = max(mxDiff, mxVal-nums[i]);
        }

        return mxTriplet;
    }
};