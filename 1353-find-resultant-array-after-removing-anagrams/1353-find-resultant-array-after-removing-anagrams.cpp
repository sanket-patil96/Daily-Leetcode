class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        // just need to sort every word to see if its anagram or not

        vector<string> ans;
        ans.push_back(words[0]);

        for(int i = 1; i < words.size(); i++) {
            string w1 = words[i];
            sort(w1.begin(), w1.end());
            
            string w2 = words[i-1];
            sort(w2.begin(), w2.end());
            
            if(w1 != w2) 
                ans.push_back(words[i]);
        }

        return ans;
    }
};