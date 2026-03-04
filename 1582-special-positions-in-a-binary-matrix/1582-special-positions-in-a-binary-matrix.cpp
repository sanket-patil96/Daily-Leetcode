class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        // brute force: 
        // whenever we see 1, check its row & col, 

        // better:
        // precompute every row & col for counting no.of 1's in it
        // then for each place where 1 is found check if its particular row & col
        // have only Single 1 in it which is current 1 itself

        int n = mat.size();
        int m = mat[0].size();
        vector<int> rows(n, 0), cols(m, 0);

        // count 1's in each row
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1)
                    rows[i]++;
            }
        }

        // count 1's in each col
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[j][i] == 1)           // j is for row here, so access as [j][i]
                    cols[i]++;
            }
        }

        // now start checking for special positions
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1)
                    ans++;
            }
        }

        return ans;
    }
};