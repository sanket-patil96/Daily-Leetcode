class Solution {
public:
    int minChanges(string s) {
        // compare min of 2 length string, one with its next, if both are different
        // then increment result as we need to flip that bit

        int res = 0;
        for(int i = 0; i < s.size()-1; i+=2) 
            if(s[i] != s[i+1])
                res++;

        return res;
    }
};