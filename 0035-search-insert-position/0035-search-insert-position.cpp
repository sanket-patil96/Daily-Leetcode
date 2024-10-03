class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        // corner cases
        if(nums[0] >= target)
            return 0;

        if(nums[nums.size()-1] < target) 
            return nums.size();

        int low = 0;
        int high = nums.size()-1;   
        int mid;

        while(low <= high) {
            mid = (low + high) / 2;

            if(nums[mid] == target) 
                return mid;

            if(nums[mid] > target)
                high = mid - 1;

            else 
                low = mid + 1;
        }

        // high & low will cross then low position is the answer
        return low;
    }
};