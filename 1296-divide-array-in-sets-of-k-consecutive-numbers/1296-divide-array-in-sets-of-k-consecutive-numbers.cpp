class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        // we have to  find K **Consecutive numbers**, like 1,2,3,.. and check if its group of k 
        // store every element in map with its count
        // traverse the array, and find if it can be a starting point of a sequence like in 
        // exp: [1,3,2,4] k = 2 here 1 is starting point of sequence for [1,2] and 3 is starting point of sequence [3,4] there is 2 before 3 but we used it in previous sequence so it can't be considered
        // so start from such point, and try to create group of k subarray, return true if we can for all groups
        // sorting can help to find all the starting points of consecutive numbers together like [1,1,1,2,2,2,3,3,3,...]
        
        int n = nums.size(); 
        sort(nums.begin(), nums.end());

        unordered_map<int, int> mp;
        for(int i: nums) 
            mp[i]++;

        for(int i: nums) {
            if(mp[i] == 0)    continue;       // means current element already got picked in previous set

            for(int cnt = 0; cnt < k; cnt++) {
                if(mp[i+cnt] == 0) return false;        // decrese freq. as we used it in this set
                mp[i+cnt]--;    
            }
        }

        return true; 
    }
};