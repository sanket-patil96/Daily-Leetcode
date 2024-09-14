class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        // observation of this question was-
        // the question said that we need to find that subarray which has a maximum AND sum out of all subarrays.
        // so from this we can infer that max element in the whole array is the only 1 element whose subarray can give maximum AND ,which indicates that subarray can only have that maximum number in it or else alone it will be forming a subarray of size 1.
        // so we can find maximum element in the array and check if it occur in a continuous subarray and return the respective length.
        
        int maxi = *max_element(nums.begin(), nums.end());
        int res = 0;
        int cnt = 0;        // contigious matching to max number

        for(auto i: nums) {
            if(i == maxi)
                cnt++;
            else  {
                res = max(res, cnt);
                cnt = 0;
            }
        }

        res = max(res, cnt);

        return res;
    }
};