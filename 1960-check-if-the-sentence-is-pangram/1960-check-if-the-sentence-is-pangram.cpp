class Solution {
public:
    bool checkIfPangram(string sentence) {
        // copy pasted
        // We iterate over 'sentence' for 26 times, one for each letter 'currChar'.
//         for (int i = 0; i < 26; ++i) {
//             char currChar = 'a' + i;
            
//             // If 'sentence' doesn't contain currChar, it is not a pangram.
//             if (sentence.find(currChar) == string::npos)
//                 return false;
//         }
        
//         // If we manage to find all 26 letters, it is a pangram.
//         return true;
        
        // using sets
        // Add every letter of 'sentence' to hash set 'seen'.
        unordered_set<char> seen(sentence.begin(), sentence.end());
        
        // If the size of 'seen' is 26, then 'sentence' is a pangram.
        return seen.size() == 26;
    }
};