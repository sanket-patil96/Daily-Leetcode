class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums[0] + nums[1] <= nums[2])
            return "none";
        
        unordered_set<int> s;

        for(auto num: nums)
            s.insert(num);

        if(s.size() == 1)
            return "equilateral";

        if(s.size() == 2)
            return "isosceles";
        
        if(s.size() == 3)
            return "scalene";
        
        return "none";
    }
};