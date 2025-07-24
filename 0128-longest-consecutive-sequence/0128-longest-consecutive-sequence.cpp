class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // store elems in set
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        int cnt;

        for(int i = 0; i < nums.size(); i++) {
            // // if previous present in map then do nothing, wait for it's root elem found
            if(s.find(nums[i]-1) != s.end()) 
                continue;
            
            // if it's previous not present then we can say its new beginning
            cnt = 1;
            // while we find its consecutive increment cnt
            while(s.find(nums[i] + cnt) != s.end()) {
                // to avoid multiple checking for same number(nums can contain duplicates) delete it from set to avoid TLE
                s.erase(nums[i]+cnt);
                cnt++;
            }
            
            res = max(res, cnt);
        }

        return res;
    }
};