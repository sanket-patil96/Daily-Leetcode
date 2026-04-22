class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        // lets try brute force first:
        // for every query[i] find the mismatched characters from dictonary words
        // and if mismatches <= 2 then put that query[i] in answer array

        vector<string> ans;

        for(auto q: queries) {
            for(auto word: dictionary) {
                int mismatch = 0;
                for(int i = 0; i < q.size() && mismatch <= 2; i++) 
                    if(q[i] != word[i]) mismatch++;

                if(mismatch <= 2) {
                    ans.push_back(q);
                    break;      // don't need to check with further words
                }
            }
        }

        return ans;
    }
};