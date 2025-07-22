class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // we use moore's voting algorithm
        // majority element calcel out other elements

        int majo;
        int cnt = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(cnt == 0) {
                majo = nums[i];
                cnt = 1;
            }
            else if(nums[i] == majo)
                cnt++;
            else 
                cnt--;
        }

        return majo;
    }
};