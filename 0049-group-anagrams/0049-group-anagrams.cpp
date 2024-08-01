class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(auto str: strs) {
            string original = str;
            sort(str.begin(), str.end());
            mp[str].push_back(original);
        }

        vector<vector<string>> ans;
        for(auto i: mp)
            ans.push_back(i.second);

        return ans;
    }
};