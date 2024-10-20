class Solution {
public:
    vector<string> stringSequence(string target) {
        // if the current char matches to ith position of target then we add it in answer
        // and also add another "a" so it comes on last of the string and we can change the last character
        vector<string> ans;
        string s = "a";               // at first only key1 can be pressed
        ans.push_back(s);

        for(int i = 0; i < target.size(); ) {
            s = ans.back();
            char last = s[s.size()-1];          // get the last character from on screen string(previous string)

            // press key1
            if(last == target[i]) {
                // ans.push_back(s);
                ans.push_back(s+"a");       // adding extra a so we can change it on next key press
                i++;
            }
            // press key2
            else {
                ans.back();
                last = last == 'z'? 'a' : last+1;           // get next character
                string newStr = s.substr(0, s.size()-1) + last;         // using substiring exclude the last character coz we are changing it

                ans.push_back(newStr);
            }
        }

        // the above code added extra "a" when last character matches the last char of target
        ans.pop_back();
        return ans;
    }
};