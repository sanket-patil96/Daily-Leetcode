class Solution {
public:
    int backtrack(int start, unordered_set<string> &seen, const string &s) {
        if(start >= s.size()) {
            return 0;
        }

        int maxSplits = 0;
        for(int end = start+1; end <= s.size(); ++end) {
            string substr = s.substr(start, end-start);
            if(seen.find(substr) == seen.end()) {
                seen.insert(substr);
                maxSplits = max(maxSplits, 1+backtrack(end, seen, s));
                seen.erase(substr);
            }
        }

        return maxSplits;
    }


    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        return backtrack(0, seen, s);
    }
};