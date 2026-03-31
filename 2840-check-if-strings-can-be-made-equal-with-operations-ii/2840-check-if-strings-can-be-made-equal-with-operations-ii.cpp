class Solution {
public:
    bool checkStrings(string s1, string s2) {
        // CASE 1: to make s1 same as s2, most important is that, the frequency
        // of each character should match, if that doesn't match then 
        // we can't make them look-alike
        // else there's chance of making them equal by swapping
        // CASE 2: swaps must be done if difference is even!
        // means, that characters at even indexes will remain at even index after any number of swaps and so does characters at odd indexes.
        
        // first check for CASE 1 using map, 
        // add all chars from s1, and while traversing s2, reduce the freq of that char from map
        // if freq is 0 or  char doesn't exist in map then return false
        // if it survived then move to check CASE 2,
        // for CASE 2: create evn & odd maps, and fill both array chars in that according to  their parity
        // at last each element on each map should have even freqeuncy, means distribution is correct!

        if(s1.size() != s2.size())
            return false;

        unordered_map<char, int> mp;

        for(int i = 0; i < s1.size(); i++) {
            mp[s1[i]]++;
        }

        // check freq match in s2
        for(int i = 0; i < s2.size(); i++) {
            if(!mp.count(s2[i]) || mp[s2[i]] == 0)
                return false;
            mp[s2[i]]--;
        }

        // here it comes means, the frequencies match!
        // now check for even/odd indices

        unordered_map<char, int> evn, odd;

        for(int i = 0; i < s2.size(); i++) {
            if(i % 2) {
                odd[s2[i]]++;
                odd[s1[i]]++;
            }
            else {
                evn[s1[i]]++;
                evn[s2[i]]++;
            }
        }

        // now check if frequencies are evn
        for(auto [key, val]: evn)
            if(val % 2)
                return false;

        for(auto [key, val]: odd)
            if(val % 2)
                return false;

        return true;
    }
};