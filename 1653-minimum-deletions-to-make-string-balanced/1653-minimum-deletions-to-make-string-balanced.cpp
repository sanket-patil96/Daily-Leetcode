class Solution {
public:
    int minimumDeletions(string s) {
        // need to find no.of b's before it, & no.of a's after it
        int n = s.size();

        vector<int> a(n), b(n);
        int cntA = 0, cntB = 0;
        
        for(int i = 0; i < n; i++) {
            b[i] = cntB;
            if(s[i] == 'b')
                cntB++;
        }

        for(int i = n-1; i >= 0; i--) {
            a[i] = cntA;
            if(s[i] == 'a')
                cntA++;
        }

        int minCost = INT_MAX;
        for(int i = 0; i < n; i++) {
            minCost = min(minCost, a[i]+b[i]);
        }
        
        return minCost;
    }
};