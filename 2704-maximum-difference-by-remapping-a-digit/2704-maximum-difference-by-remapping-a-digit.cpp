class Solution {
public:
    int minMaxDifference(int num) {
        // -- to Maximize num:
        // we can get max numbere by only replacing the first digit then whatever it is without 9 (coz itself its max)
        // if first digit is 9 then find the next smaller than 9 & replace the first one with its all occurances
        // -- to minimize num:
        // just make the first digit 0 (and its all occurances)

        // --- simplified code than first one ---

        // first convert num to string
        string s = to_string(num);
        string t = s;
        size_t pos = s.find_first_not_of('9');      // convert first non-zero

        if (pos != string::npos) {
            char a = s[pos];
            replace(s.begin(), s.end(), a, '9');
        }

        char b = t[0];
        replace(t.begin(), t.end(), b, '0');        // replace all occurances of first digit to 0
        
        return stoi(s) - stoi(t);
    }
};