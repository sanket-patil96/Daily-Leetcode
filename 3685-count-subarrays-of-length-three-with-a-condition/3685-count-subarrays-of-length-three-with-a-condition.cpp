class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        // we can do this using sliding window approach
        int cnt = 0;
        
        // first window check
        for(int i = 2; i < nums.size(); i++) {
            // cout << nums[i] + nums[i-2] << "   " <<  (nums[i-1]/2.0) << endl;
            if(nums[i] + nums[i-2] == (nums[i-1]/2.0))
                cnt++;
        }

        return cnt;
    }
};