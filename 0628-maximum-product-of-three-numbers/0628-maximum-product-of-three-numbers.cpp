class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // if there are negatives in array then 2 negatives can give positive product that
        // can be more than top positives in array
        // so check if negatives > 2 && they are greatetr equal top positive elem then 
        // make product of that 2 negatives & 1 top positive elem
        // do this if only 2 negative & 1 max positive give product than big positive 3 gives
        // if all are negatives OR all positives then make product of sorted arrays last 3 items
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int cntNeg = 0;
        for(auto i: nums) {
            if(i < 0)
                cntNeg++;
        }

        // means it's negatives greater than 2 & should not equal to size, second check is for checking 
        // if there are not all negatives in arr 
        if(cntNeg >= 2 && cntNeg < nums.size()) {
            if(nums[0]*nums[1]*nums[n-1] > nums[n-3]*nums[n-2]*nums[n-1]) {
                int maxProduct = nums[0]*nums[1]*nums[n-1];     // max 2 negative values product with top positive coz they can make big product
                return maxProduct;
            }
        }

        // else simply do top 3 elems product
        int maxProduct = nums[n-1] * nums[n-2] * nums[n-3];
        
        return maxProduct;
    }
};