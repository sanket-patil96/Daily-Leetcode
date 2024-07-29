class Solution {
public:
    void solve(int open, int close, string str, vector<string> &ans) {

        if(open == 0 && close == 0) {
            ans.push_back(str);
            return;
        }

        if(open > 0) {
            // open -= 1;
            // str += '(';
            solve(open-1, close, str+'(', ans);
            // str.pop_back();
        }

        // this condition means, you only close a parenthesis if there an opening bracket already present
        // By this way close bracket will never come in befor start bracket. i.e ')('
        if(open < close) {
            // close -= 1;
            // str += ')';
            solve(open, close-1, str+')', ans);
        }

    }
    
    vector<string> generateParenthesis(int n) {
        // if there are less no of remaining open brackets remain then only we put closign bracket 
        // that's how we can generate valid parenthesis
        vector<string> ans;
        int open = n;
        int close = n;

        solve(open, close, "", ans);
        // ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};