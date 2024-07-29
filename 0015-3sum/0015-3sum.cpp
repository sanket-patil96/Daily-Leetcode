class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        int n = nums.size();
        vector<vector<int>> res;
        
        for(int i = 0; i < n; i++) {
            int s = i+1, e = n-1;
            if(i != 0 && nums[i] == nums[i-1])
                continue;
            while(s < e) {
                if(nums[s]+nums[e] < -nums[i])
                    s++;
                else if(nums[s]+nums[e] > -nums[i])
                    e--;
                else {
                    res.push_back({nums[i], nums[s++], nums[e--]});
                }
            }
        }


        // remove duplicates
        res.erase(unique(res.begin(), res.end()), res.end());

        return res;
    }
};