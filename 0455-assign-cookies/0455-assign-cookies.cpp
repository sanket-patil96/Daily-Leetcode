class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int m = s.size();
        int j = 0;      // for s

        for(int i = 0; i < g.size(); i++) {
            while(j < m && s[j] < g[i]) 
                j++;
            
            if(j == m)
                return res;

            // means we are on s[j] which can satisfy the g[i] childs greed
            j++;
            res++;
        }

        return res;
    }
};