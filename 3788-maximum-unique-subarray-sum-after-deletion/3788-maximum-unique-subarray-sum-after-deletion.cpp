class Solution {
public:
    int maxSum(vector<int>& nums) {
        // method 3: save sorting time with space comprimising
        unordered_set<int> positiveNumsSet;
        for (int num : nums) 
            if (num > 0) 
                positiveNumsSet.emplace(num);
        
        if (positiveNumsSet.empty()) 
            return *max_element(nums.begin(), nums.end());
        
        return accumulate(positiveNumsSet.begin(), positiveNumsSet.end(), 0);
    }
};