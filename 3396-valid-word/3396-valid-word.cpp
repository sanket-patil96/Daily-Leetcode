class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3)
            return false;

        string abc = "abcdefghijklmnopqrstuvwxyz";
        string vowel = "aeiou";

        transform(word.begin(), word.end(), word.begin(), ::tolower);

        bool isVowel = false;
        bool isConso = false;

        for(int i = 0; i < word.size(); i++) {
            if(isdigit(word[i]))   continue;

            // it should be alphabetical character
            if(abc.find(word[i]) != string::npos) {
                if(vowel.find(word[i]) != string::npos) 
                    isVowel = true;
                else 
                    isConso = true;
            }
            else
                return false;
        }

        return (isVowel && isConso);
    }
};