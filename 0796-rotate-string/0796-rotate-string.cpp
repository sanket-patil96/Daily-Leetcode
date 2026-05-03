class Solution {
public:
    bool rotateString(string s, string goal) {
        // connect string s to itself and if goal is present in it then its true
        if(goal.size() != s.size())
            return false;
        s += s;

        if(s.find(goal) != string::npos) 
            return true;

        return false;
    }
};