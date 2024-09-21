class Solution {
public:
    vector<int> lexicalOrder(int n) {
        // store all numbers from 1 to n in string array then sort the array
        // then again store all sorted values sequentially in integer array

        vector<string> lex;
        for(int i = 1; i <= n; i++) 
            lex.push_back(to_string(i));
        
        sort(lex.begin(), lex.end());
        
        vector<int> ans;
        for(auto i: lex)
            ans.push_back(stoi(i));

        return ans;
    }
};