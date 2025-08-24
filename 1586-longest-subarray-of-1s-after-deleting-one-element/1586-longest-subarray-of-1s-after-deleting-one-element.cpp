class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int res = 0;
        int st = 0;         // start pointer of current window
        bool flag = false;  // true indicates that we deleted 1 zero already so we can't have another 0 in current window

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0 && !flag)
                flag = true;

            else if(nums[i] == 0 && flag) {
                while(nums[st] != 0) {
                    st++;
                }

                // we moved from last deleted 0, now we free to delete current zero
                st++;               
                // flag = false;       
            }

            res = max(res, flag ? i-st : i-st+1);
            cout << i << " " << st << " " << res << endl;
        }


        // if there is no zero in whole array then we have to delete one '1'
        if(!flag)
            res--;

        return res;
    }
};