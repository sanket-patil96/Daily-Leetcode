class Solution {
public:
    int countPartitions(vector<int>& nums) {
        // first get the suffix sum of nums
        int n = nums.size();
        vector<int> suff(n);
        
        for(int i = n-2; i >= 0; i--) {
            suff[i] = suff[i+1] + nums[i+1];
        }

        int cnt = 0;
        int pref = 0;
        for(int i = 0; i < n-1; i++) {
            pref += nums[i];

            if((pref + suff[i]) % 2 == 0)
                cnt++;
        }

        return cnt;
    }
};