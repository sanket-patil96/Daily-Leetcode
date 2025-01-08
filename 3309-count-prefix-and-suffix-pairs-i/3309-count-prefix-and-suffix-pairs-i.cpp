class Solution {
public:
    bool check(string s1, string s2) {
        bool flag = false;
        
        // check if s1 is prefix of s2
        auto res = mismatch(s1.begin(), s1.end(), s2.begin());
        if(res.first == s1.end())
            flag = true;
        
        // check if s1 is suffix of s2
        bool result = equal(s1.rbegin(), s1.rend(), s2.rbegin());

        return flag && result;
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(check(words[i], words[j]))
                    cnt++;
            }
        }
        
        return cnt;
    }
};