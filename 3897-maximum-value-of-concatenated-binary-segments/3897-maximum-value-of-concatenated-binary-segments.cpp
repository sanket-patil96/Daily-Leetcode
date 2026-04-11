class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        // first create a semgents push the segment into a container, segment = {1's, 0's}
        // for comparing 2 sengments - A = seg1 + seg2, B = seg2 + seg1, 
        // while concatenation prioritise the segments which gives higher integer value, like A > B then first add A, or vice versa
        // get the integer value of the final binary number

        // we don't generate binary number, it will get huge, so just store the {ones, zeros} in segments
        vector<pair<int, int>> seg;

        int n = nums1.size();

        for(int i = 0; i < n; i++) {
            seg.push_back({nums1[i], nums0[i]});
        }

        sort(seg.begin(), seg.end(), cmp);

        long long ans = 0;
        int mod = 1e9 + 7;

        for(auto [ones, zeros]: seg) {
            for(int i = 0; i < ones; i++)
                ans = (ans * 2 + 1) % mod;
            
            for(int i = 0; i < zeros; i++)
                ans = (ans * 2) % mod;
        }

        return ans;
    }

    static bool cmp(pair<int, int> &A, pair<int, int> &B) {
        // this fails:
        // if(A.first != B.first)
        //     return A.first > B.first;   // more 1's first

        // return A.second > B.second;    // fewer 0's first

        string AB = string(A.first, 1) + string(A.second, 0) +
                    string(B.first, 1) + string(B.second, 0);
        
        string BA = string(B.first, 1) + string(B.second, 0) +
                    string(A.first, 1) + string(A.second, 0);

        return AB > BA;
    }
};