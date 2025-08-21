class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // We want the longest subarray that contains at most k zeros (because we can flip up to k zeros into ones).
        // A subarray is defined by a window [st … i].
        // As we move the right pointer i, we may encounter zeros.
        // Each zero "costs" us one flip (k--).
        // If we exceed the allowed flips (k < 0), we shrink the window from the left (st++) until the window becomes valid again.
        // At every step, the window length (i - st + 1) is a candidate answer.
        
        int st = 0;     // left pointer (start of window)
        int ans = 0;    // maxLength

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                k--;
            }

            while(k < 0) {
                if(nums[st] == 0)
                    k++;            // give back the flip

                st++;               // shrink window from left 
            }

            ans = max(ans, i-st+1);
        }

        return ans;
    }
};