class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // moore's voting algorithm:
        // majority element will cancel out other elements [5, 5, 5, 4, 3]; [5,5] cacels [4,3] 
        // remain 5 is our answer
        // so which element is not cancel out is our possible answer 
        

        int majority = nums[0];
        int cnt = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == majority)
                cnt++;
                
            else {
                cnt--;
                if(cnt == 0) {
                    majority = nums[i];
                    cnt = 1;
                }
            }
        }

        return majority;
    }
};