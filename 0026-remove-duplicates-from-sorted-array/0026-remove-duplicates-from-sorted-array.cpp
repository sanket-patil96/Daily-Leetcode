class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = 1;

        while(j < nums.size()) {
            nums[i] = nums[j];

            if(nums[i] != nums[i-1]) 
                i++;
            j++;
        }

        return i;
    }
};