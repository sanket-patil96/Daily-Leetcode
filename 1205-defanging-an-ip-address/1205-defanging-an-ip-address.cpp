class Solution {
public:
    string defangIPaddr(string address) {
        string ans = "";

        for(auto c: address) {
            if(c == '.') {
                ans += "[.]";
                continue;
            }

            ans += c;
        }

        return ans;
    }
};