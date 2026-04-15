class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // better approach: time: O(N logN) space: O(N)
        // sort array and count previous numbers for current index

        // presearve the original ordering
        vector<int> original = nums;

        sort(nums.begin(), nums.end());

        vector<int> ans;
        int n = nums.size();
        unordered_map<int, int> mp;     // map numbers with its lesser count

        for(int i = 0; i < n; i++) {
            if(i != 0 && nums[i] == nums[i-1])      // if previous number is same as current then don't count that as less for current
                continue;
            else
                mp[nums[i]] = i;
        }

        for(int i: original)
            ans.push_back(mp[i]);

        return ans;
    }
};