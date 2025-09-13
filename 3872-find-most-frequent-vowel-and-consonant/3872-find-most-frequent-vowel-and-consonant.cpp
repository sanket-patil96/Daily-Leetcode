class Solution {
public:
    int maxFreqSum(string s) {
        // store frequency of all characters
        unordered_map<char, int> freq;

        int mxVowel = 0;
        int mxCons = 0;

        for(auto c: s)
            freq[c]++;

        for(auto [c, f]: freq) {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                mxVowel = max(mxVowel, f);
            else 
                mxCons = max(mxCons, f);
        }

        return mxVowel + mxCons;
    }
};