class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        // we have to  find K **Consecutive numbers**, like 1,2,3,.. and check if its group of k 
        // store every element in map with its count
        // traverse the array, and find if it can be a starting point of a sequence like in 
        // exp: [1,3,2,4] k = 2 here 1 is starting point of sequence for [1,2] and 3 is starting point of sequence [3,4] there  is 2 before 3 but we used it in previous sequence so it can't be considered
        // so start from such point, and try to create group of k subarray, return true if we can for all groups
        
        int n = nums.size(); 

        unordered_map<int, int> mp;
        for(int i: nums) 
            mp[i]++;

        int totalGroups = 0;                // take count of total formed sets

        // sorting can help to find all the starting points together
        sort(nums.begin(), nums.end());

        for(int i: nums) {
            if(mp[i] < 0 || mp[i-1] > 0)    continue;       // means it has its previous consecutive element and its not completely used in other sets

            // try to find all sets that start with i when its frequency is > 0
            while(mp[i] > 0) {
                int cnt = 1;
                while(cnt < k && mp[i+cnt] > 0) {
                    mp[i+cnt]--;        // decrese freq. as we used it in this set
                    cnt++;
                }

                mp[i]--;        

                if(cnt != k)    return false;       // we can't made a segment of k consecutive numbers
                totalGroups++;          
            }
        }

        // total groups should form a complete divided array
        return totalGroups == (n/k);   
    }
};