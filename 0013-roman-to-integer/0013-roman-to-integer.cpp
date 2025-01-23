class Solution {
public:
    int romanToInt(string s) {
        // first we map the roman number with its currosponding values
        unordered_map<int, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;


        int ans = mp[s[s.size()-1]];

        for(int i = s.size()-2; i >= 0; i--) {
            // if current value is less then next value
            if(mp[s[i]] < mp[s[i+1]])
                ans -= mp[s[i]];

            else 
                ans += mp[s[i]];
        }

        return ans;
    }
};