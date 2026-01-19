class Solution {
public:
    int countPartitions(vector<int>& nums) {
        // first get the total sum, and maintain prefix sum, 
        // prefix sum is of subarray[0..i], and total-prefixSum = subarry[i+1,..n-1]
        // difference of both partition is: pref - (total-pref), if its even then count++;

        int n = nums.size();
        int total = 0;
        
        for(int i = 0; i < n; i++)
            total += nums[i];
        
        int cnt = 0;
        int pref = 0;

        for(int i = 0; i < n-1; i++) {
            pref += nums[i];

            if((pref + total-pref) % 2 == 0)
                cnt++;
        }

        return cnt;
    }
};