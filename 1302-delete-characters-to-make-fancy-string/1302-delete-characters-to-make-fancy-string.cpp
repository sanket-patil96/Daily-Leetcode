class Solution {
public:
    string makeFancyString(string s) {
        int cnt = 1;
        string ans = "";
        ans += s[0];

        for(int i = 1; i < s.size(); i++) {
            
            if(s[i] == s[i-1]) {
                if(cnt == 2)        // dont add third same char
                    continue;
                ans += s[i];
                cnt++;
            }
            else {
                ans += s[i];
                cnt = 1;        // reseat it
            }
        }

        return ans;
    }
};