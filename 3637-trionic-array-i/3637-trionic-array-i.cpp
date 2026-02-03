class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        // first run loop till p, means run till we have next element greater
        // 2nd run till we have next element smaller
        // 3rd again run till next element is greater
        // so at last we should reach last element, and before 3 loops if i reach n
        // then there can't be such p & q
        
        int n = nums.size();
        int i  = 0;
        
        while(i < n-1 && nums[i] < nums[i+1]) {
            i++;
            continue;
        }
        
        if(i == 0 || i == n-1)
            return false;
            
        while(i < n-1 && nums[i] > nums[i+1]) {
            i++;
            continue;
        }
        
        if(i == n-1)
            return false;

        while(i < n-1 && nums[i] < nums[i+1]) {
            i++;
            continue;
        }

        return i == n-1;
    }
};