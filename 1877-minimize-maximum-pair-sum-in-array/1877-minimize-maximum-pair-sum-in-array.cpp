class Solution {
public:
    int minPairSum(vector<int>& nums) {
        // try brute force:
        // to minimize the maximum pair sum,
        // sort the array in ascending order, pair last value(max element)
        // with first value(minimum element), then update pointers i++ & j-- & take max from all such pair

        sort(nums.begin(), nums.end());
        int maxSum = 0;

        int i = 0, j = nums.size()-1;

        
        while(i < j) {
            maxSum = max(maxSum, nums[i++] + nums[j--]);
        }

        return maxSum;
    }
};