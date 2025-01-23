class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> roman_letters = { { 1000 , "M"  } , { 900 , "CM" } , { 500 , "D"  } , { 400 , "CD" } , { 100 , "C"  } , { 90, "XC" },
                                        {  50 , "L" } , {   40 , "XL" } , {  10 ,  "X" } , {   9 , "IX" } , {   5 ,  "V" } , {  4  , "IV" } , {  1,  "I" } }; 
        string roman = "";


        for(int i = 0; i < roman_letters.size(); i++) {
            while(num >= roman_letters[i].first) {
                roman += roman_letters[i].second;
                num -= roman_letters[i].first;
            }
        }

        return roman;
    }
};