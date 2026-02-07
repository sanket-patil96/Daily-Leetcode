class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // there can be at most 2 elements with frequency more than n/3
        // so we use moore's algorithm, only modification is we use 2 variables storage
        int majo1 = INT_MIN, majo2 = INT_MIN;
        int c1 = 0, c2 = 0;

        for(auto i: nums) {
            if(c1 == 0 && majo2 != i) {
                majo1 = i;
                c1++;
            }
            else if(i == majo1) 
                c1++;
                
            else if(c2 == 0 && majo1 != i) {
                majo2 = i;
                c2++;
            }
            else if(i == majo2)
                c2++;

            else {
                c1--;
                c2--;
            }
        }

        // verify if selected are the majority or not
        c1 = 0, c2 = 0;
        for(auto i: nums) {
            if(i == majo1) c1++;
            if(i == majo2) c2++;
        }

        int n = nums.size();
        vector<int> ans;
        if(c1 > n/3)
            ans.push_back(majo1);
        if(c2 > n/3)    
            ans.push_back(majo2);

        return ans;
    }
};