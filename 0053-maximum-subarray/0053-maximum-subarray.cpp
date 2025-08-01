class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mxSum = nums[0];
        int sum = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            sum += nums[i];
            if(sum < nums[i]) 
                sum = nums[i];

            mxSum = max(mxSum, sum);
        }

        return mxSum;
    }
};