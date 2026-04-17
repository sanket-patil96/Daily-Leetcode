class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        // store the mirror of each value in map with its index
        // if current number is already appeared in map means its mirror of that index, take the difference

        unordered_map<int, int> mp;
        int minDiff = INT_MAX;

        for(int i = 0; i < nums.size(); i++) {
            int rev = reverse(nums[i]);

            if(mp.count(nums[i])) 
                minDiff = min(minDiff, i - mp[nums[i]]); 

            mp[rev] = i;
        }

        return minDiff == INT_MAX ? -1 : minDiff;
    }

    int reverse(int num) {
       string s = to_string(num);
       ::reverse(s.begin(), s.end());

       return stoi(s);
    }
};