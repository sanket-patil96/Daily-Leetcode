class Solution {
public:
    bool isVowel(char ch) {
        if(ch == 'a' || ch == 'e' ||ch == 'i' || ch == 'o' || ch == 'u')
            return true;

        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // we use prefixSum to track the vowel string found till current length
        // and while processing queries like [start-end] get prefixSum[end] and substract prefixSum of preSum[start-1]
        // so counting before start get removed from answer
        
        vector<int> preSum(words.size());

        int ind = 0;
        int prev = 0;
        for(auto word: words) {
            if(isVowel(word[0]) && isVowel(word[word.size()-1])) {
                preSum[ind] = prev+1;
                prev++;
            }
            else 
                preSum[ind] = prev;
            ind++;
        }

        vector<int> ans;
        for(auto q: queries) {
            int cnt = 0;
            if(q[0] == 0)
                cnt = preSum[q[1]];
            else
                cnt = preSum[q[1]] - preSum[q[0]-1];

            ans.push_back(cnt);
        }

        return ans;
    }
};