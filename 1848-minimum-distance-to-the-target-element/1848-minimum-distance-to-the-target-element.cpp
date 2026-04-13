class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        // just go by brute force, find each nums[i] = target and minimize the answer

        int ans = INT_MAX;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == target)
                ans = min(ans, abs(i - start));
        }

        return ans;
    }
};