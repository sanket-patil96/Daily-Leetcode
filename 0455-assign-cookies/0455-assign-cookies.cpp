class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // we just need to satisfy most of the childrens, so we first
        // get the childrens who have less greed, and assign minimum cookies to those only
        // so we can keep max cookies for childs who have high greed 
        // for this sort both vectors in increasing order

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0, n = g.size(), m = s.size();

        while(i < n && j < m) {
            if(g[i] > s[j])
                j++;
            else {
                i++;
                j++;
            }
        }
        
        // i number of childs will be satisfied
        return i;
    }
};