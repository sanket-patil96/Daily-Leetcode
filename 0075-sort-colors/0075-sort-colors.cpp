class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, hi = n-1;

        int i = 0;
        while(i <= hi) {
            if(nums[i] == 0) 
                swap(nums[i++], nums[low++]);
            else if(nums[i] == 2)
                swap(nums[i], nums[hi--]);
            else 
                i++;
        }
    }
};