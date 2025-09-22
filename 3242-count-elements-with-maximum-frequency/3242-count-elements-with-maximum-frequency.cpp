class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // set the maximum frequeuncy from all elemets
        // find the "elements" with that frequency and return

        int maxi = 0;
        unordered_map<int, int> m;
        int res = 0;

        for(int i: nums) {
            m[i]++;
            maxi = max(maxi, m[i]);
        }

        // check for freq. matches maximum freq. and add their freq. count to result 
        for(auto [n, f]: m) 
            if(f == maxi)
                res += f;
        

        return res;
    }
};