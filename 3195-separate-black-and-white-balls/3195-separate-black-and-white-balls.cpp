class Solution {
public:
    long long minimumSteps(string s) {
        // move 1 to right side (its similar problem to moving 0's to end of array, but slight change is 'adjacents' word)
        // hint 2: as per hint two: 
        
        long long ans = 0;
        int zeros = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(s[i] == '0')
                zeros++;
            else 
                ans += zeros;
        }

        return ans;
    }
};