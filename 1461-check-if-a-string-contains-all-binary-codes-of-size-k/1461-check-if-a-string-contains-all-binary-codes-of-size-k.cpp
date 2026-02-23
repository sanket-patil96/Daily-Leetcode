class Solution {
public:
    bool hasAllCodes(string s, int k) {
        // Hint 2
        // The number of distinct sub-strings should be exactly 2^k.   

        // actual count is no.of k length binaries that can be generated

        int actual = 1 << k;           // same as 2^k
        // int actual = pow(2, k);           // these are required unique substrings

        if (s.length() - k + 1 < actual)
            return false;

        unordered_set<string> st;

        // for finding no.of unique substrings we can generate from s
        for (int i = 0; i+k <= s.length(); i++) {
            st.insert(s.substr(i, k));
        }

        // compare count with actual count of how many binary strings of length k can be generated
        return st.size() == actual;
    }
};