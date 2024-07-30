class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // method 2: see in notes tab
        vector<int> res;

        for(int i = 0; i < nums.size(); i++) {
            int val = nums[abs(nums[i])-1];         // nums[i] can have negative value & index can't be negative so take absolute value
            if(val < 0) {
                res.push_back(abs(nums[i]));
                nums[abs(nums[i])-1] = abs(val);     // restore it in positive as originally
            }
            else        // flip the value 
                nums[abs(nums[i])-1] = -val;
        }

        return res;
    }
};