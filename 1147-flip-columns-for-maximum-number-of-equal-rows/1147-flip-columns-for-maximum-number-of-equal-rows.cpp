class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // idea is based on: we have to find either rows that are completely opposite or rows that are same
        // method 2: same idea just we use string and map to store count of equals
        // if a string of rows like "0011" maches to any of its fliped or original version then
        // we increment its count in the map

        unordered_map<string, int> mp;

        for(auto currentRow: matrix) {
            string original = "";
            string fliped = "";

            for(auto i: currentRow) {
                original += (i == 0 ? "0" : "1");
                fliped += (i == 1 ? "0" : "1");
            }

            mp[original]++;
            mp[fliped]++;
        }

        int res = 0;
        for(auto i: mp) {
            res = max(i.second, res);
        }

        return res;
    }
};