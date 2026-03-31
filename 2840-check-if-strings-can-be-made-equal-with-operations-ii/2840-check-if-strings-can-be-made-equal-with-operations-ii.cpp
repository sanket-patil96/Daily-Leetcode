class Solution {
public:
    bool checkStrings(string s1, string s2) {
        // Little improvement, just keep even & odd maps, and increment for s1 & decrement for s2
        // so at last freq of each should be 0, else  return false

        if(s1.size() != s2.size())
            return false;

        vector<int> evn(26, 0), odd(26, 0);

        for(int i = 0; i < s2.size(); i++) {
            if(i % 2) {
                odd[s2[i] - 'a']++;
                odd[s1[i]- 'a']--;
            }
            else {
                evn[s1[i] - 'a']++;
                evn[s2[i] -'a']--;
            }
        }

        // now check if frequencies are matching
        for(int i = 0; i < 26; i++) {
            if(evn[i] != 0 || odd[i] != 0)
                return false;
        }


        return true;
    }
};