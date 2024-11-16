class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> result;
        int n = nums.size();
        
        for(int i = 0; i < n-k+1; i++) {
            bool flag = false;
            int mx = INT_MIN;
            for(int j = 0; j < k; j++) {
                mx = max(nums[j+i], mx);
                if(j != 0 && nums[j+i] != nums[j+i-1]+1) {
                    flag = true;
                    break;
                }
            }
            if(flag) {
                result.push_back(-1);
            }
            else 
                result.push_back(mx);
        }
        return result;
    }
};