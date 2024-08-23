class Solution {
public:
    // time: O(1)
    int count(int n, int tbl[]) {
        return tbl[n & 255] + tbl[(n >> 8) & 255] + tbl[(n >> 16) & 255] +
               tbl[(n >> 24)];
    }

    void countSetBits(int n, vector<int> &ans) {
        int tbl[256];
        tbl[0] = 0;
        ans.push_back(0);

        for (int i = 1; i < 256; i++) {
            // cout << (i & (i-1)) << " ";
            tbl[i] = tbl[i & (i - 1)] + 1;
        }

        for (int i = 1; i <= n; i++)
            ans.push_back(count(i, tbl));
    }


    vector<int> countBits(int n) {
        vector<int> ans;

        // we have to give no. of 1's in i value

        // for(int i = 0; i < n+1; i++)
        // {
        //     // this function return no. of 1's in number
        //     ans[i] = __builtin_popcount(i);
        // }

        // return ans;

        // see explanation in notes
        countSetBits(n, ans);
        return ans;
    }
};