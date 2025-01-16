class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> s;

        for(auto c: sentence) 
            s.insert(c);

        return s.size() == 26;
    }
};